#include "shell.h"

/**
 * in_cdir - checks ":" if found in the cd
 * @p: pointer char (path)
 * @i: pointer of index.
 *
 * Return: 1 if the p is in the cd, 0 otherwise.
 */
int in_cdir(char *p, int *i)
{
	if (p[*i] == ':')
		return (1);

	while (p[*i] != ':' && p[*i])
		*i += 1;

	if (p[*i])
		*i += 1;

	return (0);
}

/**
 * _which - searches for a command
 * @inp: command name
 * @_environ: environment variable
 *
 * Return: location of the command.
 */
char *_which(char *inp, char **_environ)
{
	struct stat st;
	int len_inp, i, len_d;
	char *token_p, *p, *dir, *ptr_p;

	p = get_env("P", _environ);
	if (p)
	{
		ptr_p = strdup(p);
		len_inp = strlen(inp);
		token_p = strtok(ptr_p, ":");
		i = 0;
		while (token_p != NULL)
		{
			if (in_cdir(p, &i))
				if (stat(inp, &st) == 0)
					return (inp);
			len_d = strlen(token_p);
			dir = malloc(len_d + len_inp + 2);
			strcpy(dir, token_p);
			strcat(dir, "/");
			strcat(dir, inp);
			strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_p);
				return (dir);
			}
			free(dir);
			token_p = strtok(NULL, ":");
		}
		free(ptr_p);
		if (stat(inp, &st) == 0)
			return (inp);
		return (NULL);
	}
	if (inp[0] == '/')
		if (stat(inp, &st) == 0)
			return (inp);
	return (NULL);
}

/**
 * is_exec - checks if it is an executable
 * @dat: data structure
 *
 * Return: 0 if not, any other number if it does
 */
int is_exec(shell_dat *dat)
{
	int i = 0;
	char *input;
	struct stat st;

	input = dat->args[0];
	while (input[i])
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
		i++;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	handle_error(dat, 127);
	return (-1);
}

/**
 * check_err_inp - checks wether user has permissions to access
 * @dir: destination directory
 * @dat: data structure
 *
 * Return: 0 if no error
 */
int check_err_inp(char *dir, shell_dat *dat)
{
	if (dir == NULL)
	{
		handle_error(dat, 127);
		return (1);
	}

	if (strcmp(dat->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			handle_error(dat, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(dat->args[0], X_OK) == -1)
		{
			handle_error(dat, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * inp_exec - executes command
 * @dat: data structure
 *
 * Return: 1 on success.
 */
int inp_exec(shell_dat *dat)
{
	char *dir;
	int state, exec;
	pid_t pd, wpd;
	(void)wpd;

	exec = is_exec(dat);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(dat->args[0], dat->envir);
		if (check_err_inp(dir, dat) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(dat->args[0], dat->envir);
		else
			dir = dat->args[0];
		execve(dir + exec, dat->args, dat->envir);
	}
	else if (pd < 0)
	{
		perror(dat->av[0]);
		return (1);
	}
	else
	{
		do
		{
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	dat->status = state / 256;
	return (1);
}
