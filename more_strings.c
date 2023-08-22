#include "shell.h"
/**
* _putchar - printts a character
* @c: the character to be printed
* Return: count 1
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _putstr - function that prints a string
* @str: tthe string to be printed
* Return: word count
*/
int _putstr(char *str)
{
	 int i = 0, c = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		c++;
	}
	return (c);
}

/**
* str_tok - function that tokenize a string
* @string: tthe sting to b tokenize
* @delimeter: delimeter
* Return:pointer to tthe next string
*/
char *str_tok(char *string, char *delimeter)
{
	static char *old_string;
	char *new_string;

	if (string)
	{
		old_string = string;
	}
	else
	{
		if (!old_string)
			return (NULL);
		string = old_string;
	}
	while (*string && _strchr(delimeter, *string))
	{
		++string;
	}
	if (!*string)
		return (NULL);
	new_string = string;

	while (*string && !_strchr(delimeter, *string))
	{
		++string;
	}
	if (*string)
	{
		*string = '\0';
		old_string = string + 1;
	}
	else
	{
		old_string = NULL;
	}
	return (new_string);
}
