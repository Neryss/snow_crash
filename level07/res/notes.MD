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
