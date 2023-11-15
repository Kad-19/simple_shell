#include "shell.h"

/**
 * read_cmd - reads the input command
 * @eof_j: return value of getline function
 * 
 * Return: cmd string
 */
char *read_cmd(int *eof_j)
{
	size_t bufsize = 0;
	char *cmd = NULL;

	*eof_j = getline(&cmd, &bufsize, stdin);

	return (cmd);
}
