#include "shell.h"

/**
 * PRINT - Entry point
 * @cmd: first argument
 * @msg: error message
 * @line_num: to track error
 * Return: Always 0 (Success)
 */
void PRINT(char *cmd, char *msg, int line_num)
{
	char *shell = "hsh", *delim = ": ";
	char num[16];
	int j, n = line_num;
	unsigned long int l = 0;

	_putstr(shell);
	_putstr(delim);

	if (n == 0)
	{
		num[l++] = '0';
	}
	else
	{
		while (n > 0 && l < sizeof(num) - 1)
		{
			num[l++] = '0' + (n % 10);
			n /= 10;
		}
	}
	for (j = l - 1; j >= 0; j--)
	{
		write(1, &num[j], 1);
	}

	_putstr(delim);
	_putstr(cmd);
	_putstr(delim);
	_putstr(msg);
	_putstr("\n");
}


/**
 * cd_error - Entry point
 * @args: arguments
 * Return: Always 0 (Success)
 */
char *cd_error(char **args)
{
	char *message = (char *)malloc(128 * sizeof(char));

	if (message == NULL)
	{
		return (NULL);
	}

	string_cpy(message, "can't ");
	string_cat(message, " ");
	string_cat(message, args[0]);
	string_cat(message, " to ");
	string_cat(message, args[1]);

	return (message);
}
