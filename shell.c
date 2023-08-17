#include "shell.h"
/**
* main - programm that mimics like a shell
* Return: 0 on success
*/
int main(void)
{
	char *prompt = "(My_Shell)$ ", *holder;
	size_t size = 100;
	printf("%s", prompt);
	getline(&holder, &size, stdin);
	printf("%s", holder);
	return(0);
}
