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

	while (i < n)
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
	array_path *hold;

	while (hold != NULL)
	{
		hold = path->next;
		free(path->pth);
		free(path);
		path = hold;
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
	free(environ);
}
