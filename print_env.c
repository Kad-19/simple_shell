#include "shell.h"

/**
 * print_env - prints the evironment variables
 * @dat: data structure
 * 
 * Return: 1 on success.
 */
int print_env(shell_dat *dat)
{
	int i = 0, j;

	while (dat->envir[i])
	{
        j = 0;
		while (dat->envir[i][j])
			j++;

		write(STDOUT_FILENO, dat->envir[i], j);
		write(STDOUT_FILENO, "\n", 1);
        i++;
	}
	dat->status = 0;

	return (1);
}

/**
 * env_namecmp - compares env variables names
 * @env_name: name of the variable
 * @name: name to be compared
 *
 * Return: 0 if names are not the same
 */
int env_namecmp(const char *env_name, const char *name)
{
	int i;

	for (i = 0; env_name[i] != '='; i++)
	{
		if (env_name[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * get_env - get an environment variable
 * 
 * @name: name of the environment variable
 * @envir: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *get_env(const char *name, char **envir)
{
	int i, rel;
	char *ptr;

	ptr = NULL;
	rel = 0;

	for (i = 0; envir[i]; i++)
	{
		rel = env_namecmp(envir[i], name);
		if (rel)
		{
			ptr = envir[i];
			break;
		}
	}

	return (ptr + rel);
}
