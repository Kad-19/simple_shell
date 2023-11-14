#include "shell.h"

int main(void)
{
	signal(SIGINT, handle_interruption);
	shell_loop();
	return (0);
}
