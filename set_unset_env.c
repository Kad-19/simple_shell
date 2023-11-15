#include "shell.h"

/**
 * copy_dat - copies info to create
 *
 * @name: name of env
 * @value: value of env
 * Return: new env variable
 */
char *copy_dat(char *name, char *value)
{
	int len, name_len, val_len;
	char *new;

	val_len = strlen(value);
	name_len = strlen(name);
	len = val_len + name_len + 2;
	new = malloc(sizeof(char) * (len));
	strcpy(new, name);
	strcat(new, "=");
	strcat(new, value);
	strcat(new, "\0");

	return (new);
}

/**
 * set_env_val - sets an env variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @dat: data structure
 *
 */
void set_env_val(char *name, char *value, shell_dat *dat)
{
	char *var_env, *name_env;
	int i;

	for (i = 0; dat->envir[i]; i++)
	{
		var_env = strdup(dat->envir[i]);
		name_env = strtok(var_env, "=");
		if (strcmp(name_env, name) == 0)
		{
			free(dat->envir[i]);
			dat->envir[i] = copy_dat(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	dat->envir = _reallocdp(dat->envir, i, sizeof(char *) * (i + 2));
	dat->envir[i] = copy_dat(name, value);
	dat->envir[i + 1] = NULL;
}

/**
 * _setenv_cmp - compares env variables names
 * @dat: data structure
 *
 * Return: 1 on success
 */
int _setenv_cmp(shell_dat *dat)
{

	if (dat->args[1] == NULL || dat->args[2] == NULL)
	{
		handle_error(dat, -1);
		return (1);
	}

	set_env_val(dat->args[1], dat->args[2], dat);

	return (1);
}

/**
 * _unsetenv - removes an environment variable
 * @dat: data structure
 *
 * Return: 1 on success.
 */
int _unsetenv(shell_dat *dat)
{
	char *var_env, *name_env;
	char **realloc_envir;
	int j, k, i;

	if (dat->args[1] == NULL)
	{
		handle_error(dat, -1);
		return (1);
	}
	k = -1;
	for (i = 0; dat->envir[i]; i++)
	{
		var_env = strdup(dat->envir[i]);
		name_env = strtok(var_env, "=");
		if (strcmp(name_env, dat->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		handle_error(dat, -1);
		return (1);
	}
	realloc_envir = malloc(sizeof(char *) * (i));
	for (i = j = 0; dat->envir[i]; i++)
	{
		if (i != k)
		{
			realloc_envir[j] = dat->envir[i];
			j++;
		}
	}
	realloc_envir[j] = NULL;
	free(dat->envir[k]);
	free(dat->envir);
	dat->envir = realloc_envir;
	return (1);
}
