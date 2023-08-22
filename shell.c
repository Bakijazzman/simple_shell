#include "shell.h"
/**
 * main - mimics and function like a shell
 * @count: arguement count
 * @vector: arguement vector
 * Return: 0 on success
 */
int main(int count, char **vector)
{
	(void)count
	unsigned long int size = 0;
	int pro_rec = 0, interactive = isatty(STDIN_FILENO), position = 0;
	char **buffer, *prompt = "(Myshell)$ ";
	ssize_t n_char;

	while (1)
	{
		if (interactive > 1)
		{
			_putstr(prompt);
			fflush(stdout);
		}
		n_char = get_line(vector, &size, stdin);
		if (n_char < 0)
		{
			if (feof(stdin))
			{
				_putstr("exiting shell");
				exit(0);
			}
			break;
		}
		if (n_char == position || *vector[position] == '\n')
		{
			continue;
		}
		buffer = vector;
		while (*buffer)
		{
			run(*buffer, pro_rec);
			buffer++;
		}
		_free(buffer);
		pro_rec++;
	}
	return (0);
}
