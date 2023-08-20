#include "shell.h"
/**
* _stringcmp - function that compares two strings
* @s1: string1
* @s2: string2
* Return: 0-success, positive - s1 > s2, negative- s1 < s2
*/
int _stringcmp(char *s1, char *s2)
{
	int RV, i = 0;

	while (s1[i])
	{
		if (s1[i] > s2[i])
		{
			RV = s1[i] - s2[i];
			return (RV);
		}
		else if (s1[i] < s2[i])
		{
			RV = s1[i] - s2[i];
			return (RV);
		}
		i++;
	}
	return (0);
}

/**
* _strchr - function that locates a string
* @s: the string to be checked
* @c: character to be checked
* Return: pointer to the occurence of the character
*/
char *_strchr(char *s, char c)
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
