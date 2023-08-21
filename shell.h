#ifndef SHELL_H_
#define SHELL_H_

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

	int _stringlen(char *str);
	char *_stringcpy(char *dest, char *src);
	char *_stringcat(char *dest, char *src);
	char *_strchr(char *s, char c);
	int _putchar(char c);
	int _putstr(char *str);
#endif
