#include "shell.h"
/**
 * _free - frees the arguments
 * @args: tokenized arguments
 */
void  _free(char **args)
{
	int i = 0, n = 0;

	while (args[n])
		n++;

	while (i <= n)
	{
		free(args[i]);
		i++;
	}
}

/**
 * _freepath - is a function that frees the path
 * @path: is a function that frees the path
 * Return:void
 */
void _freepath(array_path *path)
{
	array_path *hold = path;

	while (hold != NULL)
	{
		path = hold->next;
		free(hold->pth);
		free(hold);
		hold = path;
	}
}
/**
 * _freeenv - is a function that frees the eniron
 * Return:void
 */
void _freeenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		free(environ[i]);
		i++;
	}
}
