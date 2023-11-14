#include "shell.h"

void shell_loop(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *empty = "\n";

	while(true)
	{
		command = NULL;
		command_size = 0;
		show_prompt();
		getline(&command, &command_size, stdin);
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		if (!strcmp(command, empty))
			continue;
		execute(command);
	}
}
