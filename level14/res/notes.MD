## Level14

So here's the final level, which doesn't contain anything, literaly.

Which means that the only mean to get a token is to mess with `getflag` which is decompiled [here](./getflag_decomp.c).

We can't use the preload method here since the program also checks for it.

We will need to use `gdb` to get what we want from [level14](./getflag), so the first check we need to bypass is the `ptrace` check since it "blocks us" from using GDB:

```c
eax = ptrace (ebx, *(gs:0x14), 0, 0, 1, 0);
if (eax < 0) {
    puts ("You should not reverse this");
    eax = 1;
    goto label_0;
}
```

And for that let's dive into GDB !

(arrows indicate important part of the GDB output)

```bash
level14@SnowCrash:/bin$ gdb -q ./getflag
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) disas main
Dump of assembler code for function main:
   0x08048946 <+0>:     push   %ebp
   0x08048947 <+1>:     mov    %esp,%ebp
   0x08048949 <+3>:     push   %ebx
   0x0804894a <+4>:     and    $0xfffffff0,%esp
   0x0804894d <+7>:     sub    $0x120,%esp
   0x08048953 <+13>:    mov    %gs:0x14,%eax
   0x08048959 <+19>:    mov    %eax,0x11c(%esp)
   0x08048960 <+26>:    xor    %eax,%eax
   0x08048962 <+28>:    movl   $0x0,0x10(%esp)
   0x0804896a <+36>:    movl   $0x0,0xc(%esp)
   0x08048972 <+44>:    movl   $0x1,0x8(%esp)
   0x0804897a <+52>:    movl   $0x0,0x4(%esp)
   0x08048982 <+60>:    movl   $0x0,(%esp)
>  0x08048989 <+67>:    call   0x8048540 <ptrace@plt>
   0x0804898e <+72>:    test   %eax,%eax              #ptrace res check
   0x08048990 <+74>:    jns    0x80489a8 <main+98>
   0x08048992 <+76>:    movl   $0x8048fa8,(%esp)
   0x08048999 <+83>:    call   0x80484e0 <puts@plt>
   0x0804899e <+88>:    mov    $0x1,%eax
   0x080489a3 <+93>:    jmp    0x8048eb2 <main+1388>
   0x080489a8 <+98>:    movl   $0x8048fc4,(%esp)
   0x080489af <+105>:   call   0x80484d0 <getenv@plt>
   0x080489b4 <+110>:   test   %eax,%eax
   0x080489b6 <+112>:   je     0x80489ea <main+164>
   0x080489b8 <+114>:   mov    0x804b040,%eax
   0x080489bd <+119>:   mov    %eax,%edx
   0x080489bf <+121>:   mov    $0x8048fd0,%eax
   0x080489c4 <+126>:   mov    %edx,0xc(%esp)
   0x080489c8 <+130>:   movl   $0x25,0x8(%esp)
   0x080489d0 <+138>:   movl   $0x1,0x4(%esp)
   0x080489d8 <+146>:   mov    %eax,(%esp)
   0x080489db <+149>:   call   0x80484c0 <fwrite@plt>
   0x080489e0 <+154>:   mov    $0x1,%eax
   0x080489e5 <+159>:   jmp    0x8048eb2 <main+1388>
   0x080489ea <+164>:   movl   $0x0,0x4(%esp)
   0x080489f2 <+172>:   movl   $0x8048ff6,(%esp)
   0x080489f9 <+179>:   call   0x8048500 <open@plt>
   0x080489fe <+184>:   test   %eax,%eax
   0x08048a00 <+186>:   jle    0x8048a34 <main+238>
   0x08048a02 <+188>:   mov    0x804b040,%eax
   0x08048a07 <+193>:   mov    %eax,%edx
   0x08048a09 <+195>:   mov    $0x8048fd0,%eax
   0x08048a0e <+200>:   mov    %edx,0xc(%esp)
   0x08048a12 <+204>:   movl   $0x25,0x8(%esp)
   0x08048a1a <+212>:   movl   $0x1,0x4(%esp)
   0x08048a22 <+220>:   mov    %eax,(%esp)
   0x08048a25 <+223>:   call   0x80484c0 <fwrite@plt>
---Type <return> to continue, or q <return> to quit---
   0x08048a2a <+228>:   mov    $0x1,%eax
   0x08048a2f <+233>:   jmp    0x8048eb2 <main+1388>
   0x08048a34 <+238>:   movl   $0x0,0x4(%esp)
   0x08048a3c <+246>:   movl   $0x8049009,(%esp)
   0x08048a43 <+253>:   call   0x804871c <syscall_open>
   0x08048a48 <+258>:   mov    %eax,0x14(%esp)
   0x08048a4c <+262>:   cmpl   $0xffffffff,0x14(%esp)
   0x08048a51 <+267>:   jne    0x8048e88 <main+1346>
   0x08048a57 <+273>:   mov    0x804b040,%eax
   0x08048a5c <+278>:   mov    %eax,%edx
   0x08048a5e <+280>:   mov    $0x804901c,%eax
   0x08048a63 <+285>:   mov    %edx,0xc(%esp)
   0x08048a67 <+289>:   movl   $0x46,0x8(%esp)
   0x08048a6f <+297>:   movl   $0x1,0x4(%esp)
   0x08048a77 <+305>:   mov    %eax,(%esp)
   0x08048a7a <+308>:   call   0x80484c0 <fwrite@plt>
   0x08048a7f <+313>:   mov    $0x1,%eax
   0x08048a84 <+318>:   jmp    0x8048eb2 <main+1388>
   0x08048a89 <+323>:   movl   $0x8049063,0x4(%esp)
   0x08048a91 <+331>:   lea    0x1c(%esp),%eax
   0x08048a95 <+335>:   mov    %eax,(%esp)
   0x08048a98 <+338>:   call   0x8048843 <isLib>
   0x08048a9d <+343>:   test   %eax,%eax
   0x08048a9f <+345>:   je     0x8048aae <main+360>
   0x08048aa1 <+347>:   movl   $0x1,0x10(%esp)
   0x08048aa9 <+355>:   jmp    0x8048e89 <main+1347>
   0x08048aae <+360>:   cmpl   $0x0,0x10(%esp)
   0x08048ab3 <+365>:   je     0x8048e89 <main+1347>
   0x08048ab9 <+371>:   movl   $0x8049068,0x4(%esp)
   0x08048ac1 <+379>:   lea    0x1c(%esp),%eax
   0x08048ac5 <+383>:   mov    %eax,(%esp)
   0x08048ac8 <+386>:   call   0x8048843 <isLib>
   0x08048acd <+391>:   test   %eax,%eax
   0x08048acf <+393>:   je     0x8048e46 <main+1280>
   0x08048ad5 <+399>:   mov    0x804b060,%eax
   0x08048ada <+404>:   mov    %eax,%edx
   0x08048adc <+406>:   mov    $0x804906c,%eax
   0x08048ae1 <+411>:   mov    %edx,0xc(%esp)
   0x08048ae5 <+415>:   movl   $0x20,0x8(%esp)
   0x08048aed <+423>:   movl   $0x1,0x4(%esp)
   0x08048af5 <+431>:   mov    %eax,(%esp)
   0x08048af8 <+434>:   call   0x80484c0 <fwrite@plt>
>  0x08048afd <+439>:   call   0x80484b0 <getuid@plt>
   0x08048b02 <+444>:   mov    %eax,0x18(%esp)
   0x08048b06 <+448>:   mov    0x18(%esp),%eax
   0x08048b0a <+452>:   cmp    $0xbbe,%eax            # getuid res check
   0x08048b0f <+457>:   je     0x8048ccb <main+901>
   0x08048b15 <+463>:   cmp    $0xbbe,%eax
---Type <return> to continue, or q <return> to quit---q
Quit

# We first create a breakpoint just after the ptrace check to modify its value

(gdb) b *main+72
Breakpoint 1 at 0x804898e
(gdb) r
Starting program: /bin/getflag
Breakpoint 1, 0x0804898e in main ()
(gdb) print $eax
$1 = -1
(gdb) set $eax=0
(gdb) b *main+452

# Then we will do the same for the UID check from `getuid()`
Breakpoint 2 at 0x8048b0a
(gdb) s
Single stepping until exit from function main,
which has no line number information.

Breakpoint 2, 0x08048b0a in main ()
(gdb) print $eax
$2 = 2014
(gdb) set $eax=3014
(gdb) print $eax
$3 = 3014

# We can then step to the end of the program which will result in a tokan print!
(gdb) s
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb)
```

## Token

7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
