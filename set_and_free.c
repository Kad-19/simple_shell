#include "shell.h"
/**
 * setdat - Initialize data
 *
 * @dat: data structure
 * @av: argument vector
 */
void setdat(shell_dat *dat, char **av)
{
	int i = 0;

	dat->av = av;
	dat->command = NULL;
	dat->args = NULL;
	dat->status = 0;
	dat->counter = 1;

	while (environ[i])
		i++;

	dat->envir = malloc(sizeof(char *) * (i + 1));
    i = 0;
	while (environ[i])
	{
		dat->envir[i] = strdup(environ[i]);
        i++;
	}

	dat->envir[i] = NULL;
	dat->pid = aux_itoa(getpid());
}
/**
 * freedat - frees data structure
 *
 * @dat: data structure
 */
void freedat(shell_dat *dat)
{
	int i = 0;

	while (dat->envir[i])
	{
		free(dat->envir[i]);
        i++;
	}

	free(dat->envir);
	free(dat->pid);
}
