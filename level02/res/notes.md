## Level 02

First of all, there is a file we can see using `ls`, `level-2.pcap`.
After a little bit of research, it is a packet exchange log.

We can look through it using `tcpdump` or this [website](https://app.packetsafari.com/analyze/l/JCDRHYoBxSZFwhMAKj5X/none/none) and find an interesting part [here](./trimmed.txt)

We can then use the file to form the required password reading byte by byte, which are send to a server.

Which will result in:

```
f t _ w a n d r [del] [del] [del] N D R e l [del] L 0 L 
```

(`7f` byte is equal to a del char)

## Password

`ft_waNDReL0L`

## Token

kooda2puivaav1idi4f57q8iq