#include "shell.h"

void shell_loop(void)
{
	char *command = NULL;
	size_t command_size = 0;

	while(true)
	{
		show_prompt();
		read_line(void);
		if (command == NULL)
			continue;
		execute(command);
	}
}
