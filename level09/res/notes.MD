## BONUS Level09

We can find a `level09` that we decompiled [here](./level09_decomp.c) but it's not really useful to take a look at it as the strings output tell us so gently "You should not reverse this".

What the executable does is quite straight forward, it rot the arguments of the index of the letter for example `aaaa` becomes `abcde`.

There is also a [token](./test.txt) (it's the output of the cat of `token`). We just created a simple program that does the same as the base executable but in reverse and pass the token output to it:

```cpp
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream	file;
	std::string		content;
	file.open("./test.txt");
	file >> content;
	for (int i = 0; i < content.length(); i++)
	{
		content[i] = content[i] - i;
	}
	std::cout << content << std::endl;
}
```

and it gives us the password for flag09:

```bash
~/Documents/snow_crash/level09/res (main*) » clang++ main.cpp
~/Documents/snow_crash/level09/res (main*) » ./a.out
f3iji1ju5yuevaus41q1afiuq
```

We can finaly su to flag09 and get the token:

```bash
level09@SnowCrash:~$ su flag09
Password: 
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
flag09@SnowCrash:~$ 
```

## Token

s5cAJpM8ev6XHw998pRWG728z