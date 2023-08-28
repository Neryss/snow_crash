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