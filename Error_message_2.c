#include "shell.h"

/**
 * exit_error - exit error message
 * @dat: data structure
 * Return: error message
 */
char *exit_error(shell_dat *dat)
{
	char *str;
	int size;
	char *error;

	str = aux_itoa(dat->counter);
	size = strlen(str) + strlen(dat->av[0]);
	size += strlen(dat->args[1]) + strlen(dat->args[0]) + 23;
	error = malloc(sizeof(char) * (size + 1));
	if (error == 0)
	{
		free(str);
        free(error);
		return (NULL);
	}
	strcpy(error, dat->av[0]);
	strcat(error, ": ");
	strcat(error, str);
	strcat(error, ": ");
	strcat(error, dat->args[0]);
	strcat(error, ": Illegal number: ");
	strcat(error, dat->args[1]);
	strcat(error, "\n\0");
	free(str);

	return (error);
}

/**
 * cmd_not_found_error - command not found error message
 * @dat: data structure
 * Return: error message
 */
char *cmd_not_found_error(shell_dat *dat)
{
	char *str;
	int size;
	char *error;

	str = aux_itoa(dat->counter);
	size = strlen(str) + strlen(dat->av[0]) ;
	size += strlen(dat->args[0]) + 16;
	error = malloc(sizeof(char) * (size + 1));
	if (error == 0)
	{
		free(str);
		free(error);
		return (NULL);
	}
	strcpy(error, dat->av[0]);
	strcat(error, ": ");
	strcat(error, str);
	strcat(error, ": ");
	strcat(error, dat->args[0]);
	strcat(error, ": not found\n");
	strcat(error, "\0");
	free(str);
	return (error);
}
