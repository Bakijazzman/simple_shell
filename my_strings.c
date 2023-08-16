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

/**
* _stringcpy - copies a string
* @dest: new string
* @src: old string
* Return: Newly copied string
*/
char *_stringcpy(char *dest, char *src)
{
	size_t i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
