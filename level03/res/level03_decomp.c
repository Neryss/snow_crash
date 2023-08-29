uint32_t dbg_main (int32_t argc, char ** argv, char ** envp) {
    int32_t var_20h;
    int32_t var_1ch;
    int32_t var_ch;
    uid_t var_8h;
    gid_t gid;
    uid_t uid;
    /* int main(int argc, char **argv, char **envp); */
    eax = getegid ();
    eax = geteuid (eax);
    eax = var_ch;
    eax = var_ch;
    eax = var_ch;
    setresgid (eax, eax, var_ch, var_ch);
    eax = var_8h;
    eax = var_8h;
    eax = var_8h;
    setresuid (eax, var_8h, var_8h);
    system ("/usr/bin/env echo Exploit me");
    return eax;
}