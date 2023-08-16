#include "shell.h"
#include <string.h>

int main(void)
{
	int check = 0;
	char *copy;
	char *syscpy;
	char *test = "count this sentence";
	check = _stringlen(test);
	syscpy = malloc(check + 1);
//	_stringcpy(copy, test);
	strcpy(syscpy, test);
	printf("%d\n", check);
	//printf("%s\n",copy);
	printf("system copy = %s\n", syscpy);
	return(0);
}
