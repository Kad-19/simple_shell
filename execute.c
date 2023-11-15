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
	return (inp_exec(dat));
}
