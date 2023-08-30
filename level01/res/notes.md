## Level 01

We can search for passwords since the last level was about a user (kinda search and hope at this point) \
We especially look for a hint at what the password for flag01 could be:

```
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

We noticed that there was an entry for said user, and it contains the hash for the password. \
Now we can use John the Ripper on our container and try some common password using a dictionnary:

```
┌──(root㉿ad1eae506c88)-[/]
└─# echo "flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash" > /tmp/pass.PASSWD
```
```
┌──(root㉿ad1eae506c88)-[/]
└─# john /tmp/pass.PASSWD
Created directory: /root/.john
Using default input encoding: UTF-8
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 256/256 AVX2])
Will run 8 OpenMP threads
Proceeding with single, rules:Single
Press 'q' or Ctrl-C to abort, almost any other key for status
Almost done: Processing the remaining buffered candidate passwords, if any.
Warning: Only 642 candidates buffered for the current salt, minimum 2048 needed for performance.
Proceeding with wordlist:/usr/share/john/password.lst
abcdefg          (flag01)
1g 0:00:00:00 DONE 2/3 (2023-01-23 13:46) 2.380g/s 120085p/s 120085c/s 120085C/s 123456..lucky0
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
```

We get a result fairly quickly: `abcdefg`

## Token

f2av5il02puano7naaf6adaaf