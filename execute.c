#include "shell.h"

void execute(const char *command)
{
	pid_t child;
	char *token;
	int status, i = 0;
	char **arguments;
	extern char **environ;

	token = strtok((char *)command, " \t\n");
	arguments = malloc(sizeof(char *) * 1024);

	while (token)
	{
		arguments[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	arguments[i] = NULL;
	child = fork();
	if (child == -1)
		perror("fork error");
	else if (child == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
	}
}
#include "shell.h"

/**
 * exec_line - finds builtins and commands
 * @dat: data structure
 *
 * Return: 1 on success.
 */
int exec_line(shell_dat *dat)
{
	int (*b)(shell_dat *dat);

	if (dat->args[0] == NULL)
		return (1);
	b = set_builtin(dat->args[0]);

	if (b != NULL)
		return (b(dat));
	return (cmd_exec(dat));
}
