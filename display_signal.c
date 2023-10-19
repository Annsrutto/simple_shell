#include "shell.h"

/**
 * handle_signal - Display a prompt when Ctrl+C is pressed.
 * @signal_number: The received signal.
 */
void handle_signal(int signal_number)
{
	if (signal_number == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}

