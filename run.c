#include "shell.h"
/**
 * split - spliting inputs into commands
 * @cmd: command recieved
 * @args: argument
 * Return: 0 on success
 */
int split(char *cmd, char *args[])
{
	char *token = str_tok(cmd, " \a\n\r\t"), *splited;
	unsigned int loop = 0;

	for (; token && 0 < (128 - 1);)
	{
		splited = token;
		while (*splited == ' ')
		{
			splited++;
		}
		if (*splited != '\0')
		{
			args[loop] = splited;
			loop++;
		}

		token = str_tok(NULL, " \a\n\r\t");
	}
	return (loop);
}
/**
 * run - execution
 * @cmd:  command inputed from stdin
 * @pro_rec: number of runs
 * Return: fork id
 */
int run(char *cmd, int pro_rec)
{
	char *input[128], path[256];
	pid_t fork_id;
	unsigned int args, n = 0;
	int RV = 0;

	args = split(cmd, input);
	input[args] = NULL;

	if (built_ins(input, pro_rec))
		return (0);
	if (access(input[n], X_OK) == -1)
	{
		string_cpy(path, "/bin/");
		string_cat(path, input[n]);
		if (access(path, X_OK) < 0)
		{
			PRINT(input[0], "not found", pro_rec);
			return (0);
		}
	}
	fork_id = fork();
	if (fork_id < 0)
		exit(EXIT_FAILURE);
	if (fork_id != 0)
		RV = _exits();
	if (fork_id == 0 && input[0][0] != '\0')
		RV = child_exit(input);

	return (RV);
}
/**
 * child_exit - entry point
 * @cmd: command inputed
 * Return: 0 on success
 */
int child_exit(char **cmd)
{
	if (cmd[0][0] == '/' || cmd[0][0] == '.')
	{
		if (execve(cmd[0], cmd, environ) < 0)
		{
			perror(cmd[0]);
			exit(1);
		}
	}
	else if (chc_path(cmd) == 1)
		exec_path(cmd);
	else
	{
		perror(cmd[0]);
		exit(1);
	}
	return (0);
}
/**
 * _exits - exit process
 * Return: fork id
 */
int _exits(void)
{
	int n;
	static int exit_status;

	wait(&n);
	if (WIFEXITED(n))
		exit_status = WEXITSTATUS(n);

	return (exit_status);
}
