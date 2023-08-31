int __cdecl main(int argc, const char **argv, const char **envp)
{
  int result; // eax
  int v4; // [esp+20h] [ebp-118h]
  int v5; // [esp+24h] [ebp-114h]
  int v6; // [esp+28h] [ebp-110h]
  int v7[67]; // [esp+2Ch] [ebp-10Ch] BYREF

  v7[64] = __readgsdword(0x14u);
  v5 = 0;
  v4 = -1;
  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) >= 0 )
  {
    if ( getenv("LD_PRELOAD") || open("/etc/ld.so.preload", 0) > 0 )
    {
      fwrite("Injection Linked lib detected exit..\n", 1u, 0x25u, stderr);
      return 1;
    }
    else
    {
      v6 = syscall_open("/proc/self/maps", 0);
      if ( v6 == -1 )
      {
        fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n", 1u, 0x46u, stderr);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          result = syscall_gets((int)v7, 256, v6);
          if ( !result )
            break;
          if ( isLib(v7, (int)"libc") )
          {
            v5 = 1;
          }
          else if ( v5 )
          {
            if ( isLib(v7, (int)"ld") )
            {
              if ( argc != 2 )
                return fwrite("You need to provide only one arg.\n", 1u, 0x22u, stderr);
              while ( ++v4 < strlen(argv[1]) )
                putchar(v4 + argv[1][v4]);
              return fputc(10, stdout);
            }
            if ( !afterSubstr(v7, (int)"00000000 00:00 0") )
              return fwrite("LD_PRELOAD detected through memory maps exit ..\n", 1u, 0x30u, stderr);
          }
        }
      }
    }
  }
  else
  {
    puts("You should not reverse this");
    return 1;
  }
  return result;
}