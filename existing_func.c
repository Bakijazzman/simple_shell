#include "shell.h"
/**
 * _env - Entry point
 *
 * Return: void
 */
int _env(void)
{
	char **env = environ;

	while (*env)
	{
		_putstr(*env);
		_putstr("\n");
		env++;
	}

	return (0);
}


/**
 * _cd - Entry point
 * @args: arguments passed
 * @line_num: command count
 * Return: void
 */
int _cd(char **args, int line_num)
{
	char *new_dir, *old_dir, cwd[1024];
	char *cd_err = cd_error(args);

	if (!args[1] || string_cmp(args[1], "~") == 0)
		new_dir = get_env("HOME");
	else if (string_cmp(args[1], "-") == 0)
		new_dir = get_env("OLDPWD");
	else
		new_dir = args[1];
	if (!new_dir)
	{
		perror("Directory not found");
		return (1);
	}
	old_dir = get_env("PWD");
	if (_setenv("OLDPWD", old_dir, 1) != 0)
	{
		perror("OLDPWD environment variable failed");
		return (1);
	}
	if (chdir(new_dir) != 0)
	{
		PRINT(args[0], cd_err, line_num);
		free(cd_err);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("current directory failed");
		free(cd_err);
		return (1);
	}
	if (_setenv("PWD", cwd, 1) != 0)
	{
		perror("PWD environment variable failed");
		free(cd_err);
		return (1);
	}
	free(cd_err);
	return (0);
}


/**
 * _setenv - mimics setenv
 * @name: name of environment variable
 * @value: environment value
 * @overwrite: replace variable
 * Return: Always 0 (Success)
 */
int _setenv(char *name, char *value, int overwrite)
{
	int i = 0, j = 0, t;
	char *env;

	if (!name || !value)
	{
		perror("Invalid arguments");
		return (1);
	}
	t = string_len(name) + string_len(value) + 2;
	env = malloc(t);
	if (!env)
	{
		perror("Memory allocation failed");
		return (1);
	}
	while (name[i] != '\0')
	{
		env[i] = name[i];
		i++;
	}
	env[i] = '=';
	while (value[j] != '\0')
	{
		env[i + j + 1] = value[j];
		j++;
	}
	env[i + j + 1] = '\0';
	if (overwrite == 0 && get_env(name) != NULL)
	{
		free(env);
		return (0);
	}
	if (setenv(name, value, overwrite) != 0)
	{
		perror("Setting environment variable failed");
		free(env);
		return (1);
	}
	free(env);
	return (0);
}

/**
 * _unsetenv - Entry point
 * @args: command and arguments
 * Return: Always 0 (Success)
 */
int _unsetenv(char **args)
{
	int i, j;
	char *name = args[1];
	int len = string_len(name);

	if (args[1] == NULL || args[2] != NULL)
	{
		perror("Invalid argument");
		return (1);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			break;
		}
	}

	return (0);
}


/**
 * EXIT - Entry point
 * @args: command and arguments
 * Return: Always 0 (Success)
 */
int EXIT(char **args)
{
	unsigned int exit_status = 0;
	unsigned int max = 1 << (sizeof(int) * 8 - 1);
	int i = 0, len = 10;

	if (args[1] != NULL)
	{
		if (args[1][0] == '+')
		{
			i = 1;
			len++;
		}

		if (args[1][i] != '\0')
		{
			while (args[1][i] != '\0')
			{
				if (i <= len && args[1][i] >= '0' && args[1][i] <= '9')
				{
					exit_status = (exit_status * 10) + (args[1][i] - '0');
				}
				else
				{
					printf("Invalid exit status.\n");
					return (-1);
				}
				i++;
			}

			if (exit_status > max - 1)
			{
				printf("Invalid exit status.\n");
				return (-1);
			}
		}
	}
	_free(args);
	exit(exit_status);
}
