#include "shell.h"

int main(void)
{
	int check = 0;
	char *test = "count this sentence";
	check = _stringlen(test);
	printf("%d\n", check);
	return(0);
}
