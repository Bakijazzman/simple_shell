#include "shell.h"
/**
 * _freeargs - is a function that frees the arguments
 * @args: this is the tokenized arguments
 * Return:void
 */
void  _free(char **args)
{
	int index;
	int len = 0;

	while (args[len] != NULL)
		len++;

	for (index = 0; index < len; index++)
	{
		free(args[index]);
	}
}

/**
 * _freepath - is a function that frees the path
 * @path: is a function that frees the path
 * Return:void
 */
void _freepath(array_path *path)
{
	array_path *temp;

	while (temp != NULL)
	{
		temp = path->next;
		free(path->pth);
		free(path);
		path = temp;
	}
}
/**
 * _freeenv - is a function that frees the eniron
 * Return:void
 */
void _freeenv(void)
{
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		free(environ[index]);
	}
	free(environ);
}