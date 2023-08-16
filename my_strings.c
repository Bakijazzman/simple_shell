#include "shell.h"
/**
* _stringlen - function that returns the length of a string
* @str: the string
* Return: the number of character
*/
int _stringlen (char *str)
{
	int count = 0;

	while (str[count])
	{
		count += 1;
	}
	return (count);
}

