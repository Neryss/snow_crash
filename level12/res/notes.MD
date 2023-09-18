## Level12

We found a file, [level12.pl](./level12.pl)

It serves as a web server. The important part being that it executes a command after passing it through a regex eval:

```lua
# to upper equivalent
$xx =~ tr/a-z/A-Z/; 
# replace every occurence of `s.*` with nothing ?
$xx =~ s/\s.*//;
```