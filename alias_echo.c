#include "shell.h"

/**
 * _itoa - Entry point
 * @value: integer to be converted
 * Return: string converted from integer
 */
char *_itoa(int value)
{
	int i, len = 0;
	int temp = value;
	char *str = (char *)malloc((len + 1) * sizeof(char));

	while (temp != 0)
	{
		len++;
		temp /= 10;
	}

	if (value == 0)
	{
		len = 1;
	}

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = len - 1; i >= 0; i--)
	{
		str[i] = '0' + (value % 10);
		value /= 10;
	}

	str[len] = '\0';

	return (str);
}

/**
 * my_echo - Entry point
 * @args: command and arguments
 * Return: Always 0 (Success)
 */
int my_echo(char **args)
{
	unsigned int i, len;
	int pro_rec = 0;

	for (i = 1; args[i] != NULL && i < 128 - 1; i++)
	{
		if (string_cmp(args[i], "$$") == 0)
		{
			echo_ppid(pro_rec);
		}
		else if (string_cmp(args[i], "$?") == 0)
		{
			echo_exit(pro_rec);
		}
		else if (args[i][0] == '$')
		{
			echo_env(pro_rec, args, i);
		}
		else
		{
			len = string_len(args[i]);
			pro_rec += write(1, args[i], len);
			pro_rec += len;
		}
		if (args[i + 1])
		{
			pro_rec += write(1, " ", 1);
			pro_rec++;
		}
	}
	return (pro_rec);
}

/**
 * echo_ppid - Entry point
 * @pro_rec: character count
 * Return: Always 0 (Success)
 */
int echo_ppid(int pro_rec)
{
	int len;
	pid_t pid;
	char *pid_str;

			pid = getpid();
			pid_str = _itoa(pid);

			if (pid_str)
			{
				len = string_len(pid_str);

				pro_rec += write(1, pid_str, len);
				free(pid_str);
			}
			return (0);
}

/**
 * echo_exit - Entry point
 * @pro_rec: character count
 * Return: Always 0 (Success)
 */
int echo_exit(int pro_rec)
{

	int exit_status = _exits();
	char *exit_status_str = _itoa(exit_status);

	if (exit_status_str)
	{
		int len = string_len(exit_status_str);

		pro_rec += write(1, exit_status_str, len);
		free(exit_status_str);
	}
	return (0);
}

/**
 * echo_env - Entry point
 * @pro_rec: character count
 * @args: arguments
 * @i: iterate variable
 * Return: Always 0 (Success)
 */
int echo_env(int pro_rec, char **args, int i)
{
	int len;
	char *value;
	char *var_name;

	var_name = args[i] + 1;
	value = get_env(var_name);

	if (value)
	{
		len = string_len(value);
		pro_rec += write(1, value, len);
		pro_rec += len;
	}
	else
		return (0);
	return (0);
}
