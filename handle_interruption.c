#include "shell.h"
/**
 * handle_interruption - disables the interruption signal
 * @signum: interruption signal
 */
void handle_interruption(int signum)
{
	(void)signum;
	_print("\nshell$ ");
}
