#include "shell.h"

int main(int ac, char **av)
{
	shell_dat data;
	(void)ac;

	signal(SIGINT, handle_interruption);
	setdat(&data, av);
	shell_loop(&data);
	freedat(&data);
	return (data.status);
}
