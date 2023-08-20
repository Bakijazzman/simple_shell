#include "shell.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putstr(char *str)
{
	int i = 0, c = 0;

	while(str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		c++;
	}
	return (c);
}
