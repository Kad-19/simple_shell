#include "shell.h"
/**
 * main - entry point
 * @av: arguments passed to the program
 * @ac: the length of the arguments passed to the program
 * Return: status
 */
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
