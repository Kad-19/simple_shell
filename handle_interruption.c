#include "shell.h"

void handle_interruption(int signum)
{
	(void) signum;
	_print("\nshell$ ");
}
