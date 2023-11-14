#include "shell.h"

/**
 * handle_error - handles error and call error functions
 * @data: data structure 
 * @err: error value
 * Return: err value
 */
int handle_error(shell_dat *data, int err)
{
	char *err_message;

	switch (err)
	{
	case 2:
        if (strcmp("exit", data->args[0]) == 0)
			err_message = exit_error(data);
		else if (strcmp("cd", data->args[0]) == 0)
			err_message = error_get_cd(data);
		break;
	case -1:
		err_message = env_error(data);
		break;
	case 126:
		err_message = error_126(data);
		break;
	case 127:
		err_message = cmd_not_found_error(data);
		break;
	}

	if (err_message)
	{
		write(STDERR_FILENO, err_message, strlen(err_message));
		free(err_message);
	}

	data->status = err;
	return (err);
}

