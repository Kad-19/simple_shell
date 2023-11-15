#include "shell.h"
/**
 * remove_comment - removes comments from the command
 * @in: input string
 *
 * Return: command line without comment
 */
char *remove_comment(char *in)
{
	int end = 0, i = 0;

	while (in[i])
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == ';' || in[i - 1] == '\t')
				end = i;
		}
	i++;
	}

	if (end != 0)
	{
		in = _realloc(in, i, end + 1);
		in[end] = '\0';
	}

	return (in);
}
