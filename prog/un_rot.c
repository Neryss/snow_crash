#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		main(void)
{
	int		fd;
	int		ret;
	unsigned char	c;
	int		i = 0;

	c = 0;
	fd = open("./token", O_RDONLY);
	ret = 1;
	while ((ret = read(fd, &c, 1)) > 0)
	{
		printf("%c", c - i);
		i++;
	}
	return (0);
}
