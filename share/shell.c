#include "shell.h"
/**
* main - programm that mimics like a shell
* @argc: arguement count
* @argv: arguement vector
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	(void)argc;
	char *prompt = "(shell)$ ", **exe;
	unsigned int c = 0;
	ssize_t n_char;
	int loop = 1, ch = 0, interactive = isatty(STDIN_FILENO);

	signal(SIGINT, _signit);
	
	while(1)
	{
		if (interactive == 1)
		{
			_putstr(prompt);
			fflush(stdout);
		}
		n_char = _getline(argv, &c, stdin);
		if (n_char < 0)
		{
			if(feof(stdin))
			{
				exit(0);
			}
			break;
		}
		if (n_char == ch || *argv[0] == '\n')
			continue;
		exe = argv;
		while(*exe)
		{
			*exe = _strtok	
		}
	}
}

/**
* _signit - handle signit
*/
void _signit()
{}
