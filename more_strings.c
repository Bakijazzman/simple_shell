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
	while (*string && str_chr(delimeter, *string))
	{
		++string;
	}
	if (!*string)
		return (NULL);
	new_string = string;

	while (*string && !str_chr(delimeter, *string))
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
/**
 * _strncmp - Entry point
 * @s1: 1st string to compare
 * @s2: 2nd string to compare
 * @n: Maximum number of characters to compare
 * Return: Always 0 (Success)
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char p1, p2;
	size_t i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; i < n; i++)
	{
		p1 = (unsigned char)s1[i];
		p2 = (unsigned char)s2[i];

		if (p1 != p2)
			return (p1 - p2);
		if (p1 == '\0')
			break;
	}

	return (0);
}
