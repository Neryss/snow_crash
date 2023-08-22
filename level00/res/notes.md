## Level 00

We can find a video on the intra [here](https://elearning.intra.42.fr/notions/snow-crash/subnotions/snow-crash/videos/snow-crash) which shows a readme file at root directory

The README file say
```
FIND this first file who can run only as flag00
```

```
level00@SnowCrash:~$ find / -user flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

We can then cat the file and find a string

```
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

After decoding it with a caesar cupher (key 15)
`nottoohardhere`
