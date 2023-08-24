int32_t _init()
{
    if (__gmon_start__ != 0)
    {
        __gmon_start__();
    }
    frame_dummy();
    return __do_global_ctors_aux();
}

int32_t sub_80483b0()
{
    int32_t var_4 = data_8049ff8;
    /* jump -> data_8049ffc */
}

int32_t setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
    /* tailcall */
    return setresuid(ruid, euid, suid);
}

int32_t sub_80483c6()
{
    /* tailcall */
    return sub_80483b0(0);
}

void free(void* mem)
{
    /* tailcall */
    return free(mem);
}

int32_t sub_80483d6()
{
    /* tailcall */
    return sub_80483b0(8);
}

char* strdup(char const* s)
{
    /* tailcall */
    return strdup(s);
}

int32_t sub_80483e6()
{
    /* tailcall */
    return sub_80483b0(0x10);
}

int32_t geteuid()
{
    /* tailcall */
    return geteuid();
}

int32_t sub_80483f6()
{
    /* tailcall */
    return sub_80483b0(0x18);
}

int32_t getegid()
{
    /* tailcall */
    return getegid();
}

int32_t sub_8048406()
{
    /* tailcall */
    return sub_80483b0(0x20);
}

int32_t __gmon_start__()
{
    /* tailcall */
    return __gmon_start__();
}

int32_t sub_8048416()
{
    /* tailcall */
    return sub_80483b0(0x28);
}

void __libc_start_main(
    int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, 
    char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), 
    void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int32_t sub_8048426()
{
    /* tailcall */
    return sub_80483b0(0x30);
}

int32_t execve()
{
    /* tailcall */
    return execve();
}

int32_t sub_8048436()
{
    /* tailcall */
    return sub_80483b0(0x38);
}

int32_t setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
    /* tailcall */
    return setresgid(rgid, egid, sgid);
}

int32_t sub_8048446()
{
    /* tailcall */
    return sub_80483b0(0x40);
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    void* const var_4 = __return_addr;
    int32_t* var_18 = &argc;
    char* esi = strdup(&data_80487d0[4]);
    char* ebx = strdup(&data_80487d0[4]);
    if (argv[1] != 0)
    {
        free(esi);
        esi = strdup(argv[1]);
        if (argv[2] != 0)
        {
            free(ebx);
            ebx = strdup(argv[2]);
        }
    }
    gid_t eax_6 = getegid();
    uid_t eax_7 = geteuid();
    setresgid(eax_6, eax_6, eax_6);
    setresuid(eax_7, eax_7, eax_7);
    char* var_2c = esi;
    char* var_28 = ebx;
    char const* const var_34 = "/usr/bin/php";
    char const* const var_30 = "/home/user/level06/level06.php";
    int32_t var_24 = 0;
    execve("/usr/bin/php", &var_34, envp, eax_7);
    return 0;
}

int32_t __convention("regparm") _start(int32_t arg1, void (* arg2)()) __noreturn
{
    int32_t var_4 = arg1;
    __libc_start_main(main, __return_addr, &arg_4, __libc_csu_init, __libc_csu_fini, arg2, &var_4);
    /* no return */
}

void __do_global_dtors_aux()
{
    if (__bss_start == 0)
    {
        uint32_t eax = dtor_idx.6161;
        if (eax < 0)
        {
            do
            {
                dtor_idx.6161 = (eax + 1);
                *(((eax + 1) << 2) + 0x8049f1c)();
                eax = dtor_idx.6161;
            } while (eax < 0);
        }
        __bss_start = 1;
    }
}

int32_t frame_dummy()
{
    return __JCR_END__;
}

int32_t syscall_open(char* arg1, int32_t arg2)
{
    int32_t esi;
    int32_t var_8 = esi;
    return syscall(sys_open {5}, arg1, arg2);
}

int32_t syscall_gets(char* arg1, int32_t arg2, int32_t arg3)
{
    int32_t edi = 0;
    char* var_14 = arg1;
    while (edi < (arg2 - 1))
    {
        int32_t eax_2 = syscall(sys_read {3}, arg3, var_14, 1);
        int32_t var_1c_1 = eax_2;
        if (eax_2 != 1)
        {
            break;
        }
        var_14 = &var_14[1];
        edi = (edi + 1);
        if (var_14[0xffffffff] == 0xa)
        {
            break;
        }
    }
    arg1[edi] = 0;
    return edi;
}

void* afterSubstr(char* arg1, char* arg2)
{
    char* edx = arg1;
    void* eax_1;
    while (true)
    {
        eax_1 = nullptr;
        if (*edx == 0)
        {
            break;
        }
        char ecx;
        void* esi_1;
        do
        {
            ecx = *(arg2 + eax_1);
            esi_1 = eax_1;
            if (ecx == 0)
            {
                break;
            }
            eax_1 = (eax_1 + 1);
        } while (ecx == *(edx + esi_1));
        if (ecx == 0)
        {
            eax_1 = (eax_1 + edx);
            break;
        }
        edx = &edx[1];
    }
    return eax_1;
}

int32_t isLib(char* arg1, char* arg2)
{
    void* eax = afterSubstr(arg1, arg2);
    int32_t edx = 0;
    if ((eax != 0 && *eax == 0x2d))
    {
        void* eax_1 = (eax + 1);
        int32_t ebx_1 = 0;
        char ecx;
        while (true)
        {
            ecx = *eax_1;
            if ((ecx - 0x30) > 9)
            {
                break;
            }
            eax_1 = (eax_1 + 1);
            ebx_1 = 1;
        }
        edx = 0;
        if ((ebx_1 != 0 && ecx == 0x2e))
        {
            void* eax_2 = (eax_1 + 1);
            int32_t ecx_1 = 0;
            while (true)
            {
                edx = *eax_2;
                if ((edx - 0x30) > 9)
                {
                    break;
                }
                eax_2 = (eax_2 + 1);
                ecx_1 = 1;
            }
            edx = 0;
            if (ecx_1 != 0)
            {
                while (true)
                {
                    ecx_1 = *".so\n"[edx];
                    if (ecx_1 == 0)
                    {
                        edx = 1;
                        break;
                    }
                    if (ecx_1 != *(eax_2 + edx))
                    {
                        edx = 0;
                        break;
                    }
                    edx = (edx + 1);
                }
            }
        }
    }
    return edx;
}

void __libc_csu_init()
{
    _init();
}

void j___libc_csu_fini()
{
    /* tailcall */
    return __libc_csu_fini();
}

void __libc_csu_fini()
{
    return;
}

int32_t __i686.get_pc_thunk.bx()
{
    return;
}

int32_t __do_global_ctors_aux()
{
    return 0xffffffff;
}

int32_t _fini()
{
    return __do_global_dtors_aux();
}

