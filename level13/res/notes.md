## Level 13

We can find a [level13](./level13) file asking us for a specific UID (4242).

We have several ways to tackle this exploit:

### GDB

We can use GDB to modify the `cmp` call as such:

```bash
/42/snow_crash/level13/res (main*) » gdb -q ./level13
Reading symbols from ./level13...
(No debugging symbols found in ./level13)
(gdb) disas main
Dump of assembler code for function main:
   0x0804858c <+0>:     push   %ebp
   0x0804858d <+1>:     mov    %esp,%ebp
   0x0804858f <+3>:     and    $0xfffffff0,%esp
   0x08048592 <+6>:     sub    $0x10,%esp
   0x08048595 <+9>:     call   0x8048380 <getuid@plt>
   0x0804859a <+14>:    cmp    $0x1092,%eax
   0x0804859f <+19>:    je     0x80485cb <main+63>
   0x080485a1 <+21>:    call   0x8048380 <getuid@plt>
   0x080485a6 <+26>:    mov    $0x80486c8,%edx
   0x080485ab <+31>:    movl   $0x1092,0x8(%esp)
   0x080485b3 <+39>:    mov    %eax,0x4(%esp)
   0x080485b7 <+43>:    mov    %edx,(%esp)
   0x080485ba <+46>:    call   0x8048360 <printf@plt>
   0x080485bf <+51>:    movl   $0x1,(%esp)
   0x080485c6 <+58>:    call   0x80483a0 <exit@plt>
   0x080485cb <+63>:    movl   $0x80486ef,(%esp)
   0x080485d2 <+70>:    call   0x8048474 <ft_des>
   0x080485d7 <+75>:    mov    $0x8048709,%edx
   0x080485dc <+80>:    mov    %eax,0x4(%esp)
   0x080485e0 <+84>:    mov    %edx,(%esp)
   0x080485e3 <+87>:    call   0x8048360 <printf@plt>
   0x080485e8 <+92>:    leave
   0x080485e9 <+93>:    ret
End of assembler dump.
```

We can then jump on the specific line which interest us by adding a breakpoint:

```bash
(gdb) b *main+14
Breakpoint 1 at 0x804859a
(gdb) r
Starting program: /home/neryss/documents/42/snow_crash/level13/res/level13
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, 0x0804859a in main ()
```

We can read and modify the reutrn of `getuid()`

```bash
(gdb) print $eax
$1 = 1000
(gdb) set $eax=4242
(gdb) print $eax
$2 = 4242
(gdb) s
Single stepping until exit from function main,
which has no line number information.
your token is 2A31L79asukciNyi8uppkEuSx
[Inferior 1 (process 14822) exited with code 050]
(gdb) exit
```

### Preload

```bash
level13@SnowCrash:/var/crash$ cat inject.c
#include <stdio.h>

__uid_t getuid()
{
        return (4242);
}

level13@SnowCrash:/var/crash$ gcc -shared -fPIC /var/crash/inject.c -o /var/crash/inject.o
level13@SnowCrash:/var/crash$ LD_PRELOAD=/var/crash/inject.o ./level13
your token is 2A31L79asukciNyi8uppkEuSx
```

## Token

2A31L79asukciNyi8uppkEuSx