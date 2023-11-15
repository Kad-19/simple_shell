#include "shell.h"

/**
 * set_builtins - gets builtin executables
 * @input: input command line
 *
 * Return: function pointer of the builtin command
 */
int (*set_builtin(char *input))(shell_dat *)
{
	int i = 0;
	builtin_li b[] = {
		{"env", print_env},
		{"exit", _exit_shell},
		{NULL, NULL}};

	while (b[i].command)
	{
		if (strcmp(b[i].command, input) == 0)
			break;
		i++;
	}

	return (b[i].call);
}
