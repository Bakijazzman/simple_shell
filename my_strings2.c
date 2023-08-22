#include "shell.h"
/**
* string_cmp - function that compares two strings
* @s1: string1
* @s2: string2
* Return: 0-success, positive - s1 > s2, negative- s1 < s2
*/
int string_cmp(char *s1, char *s2)
{
 	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
 		else
		{
			break;
	 	}
	}
	return (*s1 - *s2);
}

/**
* str_chr - function that locates a string
* @s: the string to be checked
* @c: character to be checked
* Return: pointer to the occurence of the character
*/
char *str_chr(char *s, char c)
{
	int i = 0;


	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
		if (s[i] == c)
		{
			return (&s[i]);
		}
		else
		{
			return (0);
		}
}

/**
* string_dup - duplicate a string
* @str: the string to be duplicated
* Return: pointer to the duplicated string
*/
char *string_dup(const char *str)
{
	int c = 0;
	char *t;

	if (!str)
		return (NULL);
	while (*str++)
		c++;
	t = malloc(sizeof(char) * (c + 1));
	if (!t)
		return (NULL);
	for (c++; c--;)
		t[c] = *--str;
	return (t);
}
