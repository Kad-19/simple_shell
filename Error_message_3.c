#include "shell.h"

/**
 * error_get_cd - error message of cd in get_cd
 * @dat: data structure
 *
 * Return: error message
 */
char *error_get_cd(shell_dat *dat)
{
	char *str, *msg, *error;
	int len, size;

	str = conv_itoa(dat->counter);
	if (dat->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len = strlen(dat->args[1]);
	}
	size = strlen(dat->args[0]) + strlen(dat->av[0]);
	size += strlen(msg) + strlen(str) + len + 5;
	error = malloc(sizeof(char) * (size + 1));

	if (error == 0)
	{
		free(str);
		return (NULL);
	}

	error = cd_error(dat, msg, error, str);

	free(str);

	return (error);
}

/**
 * cd_error - cd error message
 *
 * @dat: data structure
 * @msg: printed message
 * @error: output message
 * @str: counter lines
 *
 * Return: error message
 */
char *cd_error(shell_dat *dat, char *msg, char *error, char *str)
{
	char *flag;

	strcpy(error, dat->av[0]);
	strcat(error, ": ");
	strcat(error, str);
	strcat(error, ": ");
	strcat(error, dat->args[0]);
	strcat(error, msg);
	if (dat->args[1][0] == '-')
	{
		flag = malloc(3);
		flag[0] = '-';
		flag[1] = dat->args[1][1];
		flag[2] = '\0';
		strcat(error, flag);
		free(flag);
	}
	else
	{
		strcat(error, dat->args[1]);
	}
	strcat(error, "\n");
	strcat(error, "\0");
	return (error);
}
