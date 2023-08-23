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
 * check_path - is a function that checks for a command in the path
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
	linked_path *head;
	linked_path *_node = (array_path *)malloc(sizeof(array_path));

	head = _node;


	Path = _getenv("PATH");
	Path_dup = string_dup(Path);
	pth = str_tok(Path_dup, ":");
	_node->pth = _strdup(dir);

	while (pth != NULL)
	{
		pth = str_tok(NULL, ":");
		if (pth != NULL)
		{
			_node->next = (linked_path *)malloc(sizeof(linked_path));
			_node = _node->next;
			_node->pth = string_dup(dir);
		}
	}
	_node->next = NULL;

	return (head);

}
