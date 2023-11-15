#include "shell.h"
/**
 * shell_loop - Loop of shell
 *
 * @dat: data struncture
 */
void shell_loop(shell_dat *dat)
{
	char *comnd;
	int eof_j, lp_i;

	lp_i = 1;
	while (lp_i == 1)
	{
		write(STDIN_FILENO, "shell$ ", 7);
		comnd = read_cmd(&eof_j);
		if (eof_j != -1)
		{
			if (comnd == NULL)
				continue;
			lp_i = split_commands(dat, comnd);
			dat->counter += 1;
			free(comnd);
		}
		else
		{
			lp_i = 0;
			free(comnd);
		}
	}
}
