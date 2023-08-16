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
