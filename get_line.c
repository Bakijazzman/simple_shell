#include "shell.h"
/**
 * get_dir - is a function that prints the working dir
 * Return: the working directory
 */
char *get_dir()
{
	char *cwd = malloc(sizeof(char) * 1024);

	if (cwd == NULL)
	{
		perror("malloc error");
		return (NULL);
	}

	if (getcwd(cwd, 1024) != NULL)
	{
		return (cwd);
	}
	else
	{
		perror("getcwd error");
		free(cwd);
		return (NULL);
	}
}
/**
 * get_env - is a function that checks for
 * a variable in the environment
 * @name: is a a pointer to an array of characters
 * Return: a pointer if success or NULL if failed
 */


char *get_env(char *name)
{
	int i = 0;
	char *envi_ron;
	char *equals;

	while (environ[i] != NULL)
	{
		envi_ron = environ[i];
		equals = str_chr(envi_ron, '=');

		*equals = '\0';
		if (string_cmp(envi_ron, name) == 0)
		{
			*equals = '=';
			return (environ[i] + string_len(name) + 1);
		}
		*equals = '=';
		i++;
	}
	return (NULL);
}

/**
*  get_line - Read a line of input from a stream
* @lineptr: a pointer to a pointer to a buffer
* @n: pointer to the size of the buffer
* @stream: a pointer to the input stream to read from
*
* Return: the number of characters read from the stream
*/
ssize_t get_line(char **lineptr, unsigned long int *n, FILE *stream)
{
	static char buffer[1024];
	static int buffer_pos, buffer_len;
	int line_pos = 0, c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		if (buffer_pos >= buffer_len)
		{
			buffer_len = read(fileno(stream), buffer, BUFFER_SIZE);
			if (buffer_len <= 0)
				return (buffer_len);
			buffer_pos = 0;
		}
		c = buffer[buffer_pos++];
		(*lineptr)[line_pos++] = c;
		if (line_pos >= (int)(*n - 1))
		{
			*n += BUFFER_SIZE;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		if (c == '\n')
		{
			break;
		}
	}
	(*lineptr)[line_pos] = '\0';
	return ((ssize_t)line_pos);
}

/**
 * not_buff - Entry point
 * Return: error
 */
/*void not_buff(void)
{
	perror("get_line");
	exit(EXIT_FAILURE);
}*/
