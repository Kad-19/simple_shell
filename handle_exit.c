#include "shell.h"

/**
 * _exit_shell - exits the shell
 * @dat: data structure
 * 
 * Return: 0 on success.
 */
int _exit_shell(shell_dat *dat)
{
	int num, len, bignum;
    unsigned int _st;

	if (dat->args[1] != NULL)
	{
		len = strlen(dat->args[1]);
		_st = _atoi(dat->args[1]);
		num = _isdigit(dat->args[1]);
		bignum = _st > (unsigned int)INT_MAX;
		if (!num || len > 10 || bignum)
		{
			handle_error(dat, 2);
			dat->status = 2;
			return (1);
		}
		dat->status = (_st % 256);
	}
	return (0);
}
