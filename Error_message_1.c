#include "shell.h"
/**
 * error_126 - denied permission error message
 * @dat: data structure
 * Return: error message
 */
char *error_126(shell_dat *dat)
{
	char *error;
	int size;
	char *str;

	str = aux_itoa(dat->counter);
	size = strlen(str) + strlen(dat->av[0]);
	size += strlen(dat->args[0]) + 24;
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
	strcat(error, ": Permission denied\n");
	strcat(error, "\0");
	free(str);
	return (error);
}

/**
 * env_error - env error message
 * @dat: data structure
 * Return: error message
 */
char *env_error(shell_dat *dat)
{
	char *str;
	int size;
	char *msg;
	char *error;

	str = aux_itoa(dat->counter);
	msg = ": Unable to add/remove from environment\n";
	size = strlen(str) + strlen(dat->av[0]);
	size += strlen(msg) + strlen(dat->args[0]) + 4;
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
	strcat(error, msg);
	strcat(error, "\0");
	free(str);
	return (error);
}

