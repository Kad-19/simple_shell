#include "shell.h"

void _print(char *format)
{
	write(1, format, strlen(format));
}

void _read(char *command, size_t size)
{
	fgets(command, size, stdin);
	if (command == NULL)
	{
		if (feof(stdin))
		{
			_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
