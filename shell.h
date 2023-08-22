#ifndef SHELL_H_
#define SHELL_H_

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

extern char **environ;
extern int stat;
	int string_len(char *str);
	char *string_cpy(char *dest, char *src);
	char *string_cat(char *dest, char *src);
	char *str_chr(char *s, char c);
	int string_cmp(char *s1, char *s2);
	char *string_dup(const char *str);
	int _putchar(char c);
	int _putstr(char *str);
	char *str_tok(char *string, char *delimeter);
#endif
