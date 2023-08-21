#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *prompt = "(myshell)$ ", **holder;
	unsigned long int size = 0;
	ssize_t n_char;
	int interactive = isatty(STDIN_FILENO), process_count = 1;
	(void)argc;
	for (;;)
	{	if(interactive == 1)
		{
			_putstr(prompt);
			n_char  = getline(argv, &size, stdin);
			if (n_char == -1)
			{
				if (feof(stdin))
				{
					_putstr("Exiting shell .........");
					exit (0);
				}
				break;
			}
			_putstr(argv[0]);
		}
		if (n_char == 0 || *argv[0] == '\n')
			continue;
		holder = argv;
	}
	return (0);
}
