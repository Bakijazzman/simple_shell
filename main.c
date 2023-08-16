#include "shell.h"
#include <string.h>

int main(void)
{
	int check = 0, check2 = 0;
	char copy[100] = "concatenation test";
	char *syscpy, *cat;
	char *test = "count sentence";
	check = _stringlen(test);
	check2 = _stringlen(copy);
	syscpy = malloc(check + 1);
	cat = malloc(check + check2 + 1);
	_stringcpy(syscpy, test);
	
	cat = _stringcat(copy, test);
	printf("%d\n", check);
	printf("%s\n", cat);
	printf("system copy = %s\n", syscpy);
	free(syscpy);
	return(0);
}
