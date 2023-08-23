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
extern int exit_status;

/**
 * struct array_path - linked list containing each directory in the path
 * @pth: each path
 * @next: pointer to next node
 */
typedef struct array_path
{
	char *pth;
	struct array_path *next;
} array_path;

	int string_len(char *str);
	char *string_cpy(char *dest, char *src);
	char *string_cat(char *dest, char *src);
	char *str_chr(char *s, char c);
	int string_cmp(char *s1, char *s2);
	int _strncmp(char *s1, char *s2, unsigned long int n);
	char *string_dup(const char *str);
	int _putchar(char c);
	int _putstr(char *str);
	char *str_tok(char *string, char *delimeter);
	int _env(void);
	int _cd(char **args, int pro_rec);
	int _setenv(char *name, char *value, int overwrite);
	int _unsetenv(char **args);
	int EXIT(char **args);
	int execute(char **args, int pro_rec);
	char *get_dir(void);
	char *get_env(char *name);
	ssize_t get_line(char **buffer, size_t *bufsize, int fd);
	void not_buff(void);
	void PRINT(char *cmd, char *msg, int line_num);
	char *cd_error(char **args);
	int exec_path(char **args);
	int chc_path(char **args);
	array_path *_path(void);
	int split(char *cmd, char *args[]);
	int run(char *cmd, int pro_rec);
	int child_exit(char **cmd);
	int _exits(void);
	int built_ins(char **args, int line_num);
	void _free(char **args);
	void _freepath(array_path *path);
	void _freeenv(void);
#endif
