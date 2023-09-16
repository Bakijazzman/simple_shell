#include "shell.h"
/**
 * built_ins - Entry point
 * @args: command and arguments
 * @line_num: execution count
 * Return: Always 0 (Success)
 */
int built_ins(char **args, int line_num)
{
	if (args[0] == NULL)
		return (1);

	if (string_cmp(args[0], "exit") == 0)
	{
		EXIT(args);
		exit(2);
	}
	if (string_cmp(args[0], "env") == 0)
	{
		_env();
		return (1);
	}
	if (string_cmp(args[0], "cd") == 0)
	{
		_cd(args, line_num);
		return (1);
	}
	if (string_cmp(args[0], "setenv") == 0)
	{
		_setenv(args[1], args[2], 1);
		return (1);
	}
	if (string_cmp(args[0], "unsetenv") == 0)
	{
		_unsetenv(args);
		return (1);
	}
	return (0);
}
/**
 * built_ins2 - Entry point
 * @args: command and arguments
 * @line_num: execution count
 * Return: Always 0 (Success)
 */
int built_ins2(char **args, int line_num)
{
	(void) line_num;
	if (string_cmp(args[0], "echo") == 0)
	{
		my_echo(args);
		write(1, "\n", 1);
		return (1);
	}

	return (0);
}
