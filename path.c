#include "shell.h"
/**
 * exec_path - is a function that exeuctes command from the path
 * @args: is an array of tokenized commands
 * Return: The process id
 */
int exec_path(char **args)
{
	array_path *buff = _path();
	char full[1024];

	while (buff)
	{
		sprintf(full, "%s/%s", buff->pth, args[0]);
		if (access(full, F_OK) == 0)
		{
			execve(full, args, NULL);
		}
		buff = buff->next;
	}
	return (-1);

}

/**
 * chc_path - is a function that checks for a command in the path
 * @args: is a command
 * Return: pid
 */
int chc_path(char **args)
{
	array_path *buff = _path();
	char full[1024];

	while (buff)
	{
		sprintf(full, "%s/%s", buff->pth, args[0]);
		if (access(full, F_OK) == 0)
		{
			return (1);
		}
		buff = buff->next;
	}
	return (-1);
}

/**
 * link_path - is a function that creates a linked list for the path
 * Return: a pointer to the first node
 */
array_path *_path(void)
{
	char *dir, *Path, *Path_dup;
	array_path *head;
	array_path *_node = (array_path *)malloc(sizeof(array_path));

	head = _node;


	Path = get_env("PATH");
	Path_dup = string_dup(Path);
	dir = str_tok(Path_dup, ":");
	_node->pth = string_dup(dir);

	while (dir != NULL)
	{
		dir = str_tok(NULL, ":");
		if (dir != NULL)
		{
			_node->next = (array_path *)malloc(sizeof(array_path));
			_node = _node->next;
			_node->pth = string_dup(dir);
		}
	}
	_node->next = NULL;

	return (head);

}
