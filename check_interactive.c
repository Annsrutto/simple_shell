#include "shell.h"

/**
 * check_interactive - Verifies if the standard input comes from the terminal.
 *
 * Return: 0 if false, and 1 if true.
 */
int check_interactive(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		/* write(STDOUT_FILENO, "Operational in interactive mode.\n", 33); */
		return (1);
	}
	else
	{
		/* write(STDOUT_FILENO, "Operational in non-interactive mode.\n", 37); */
		return (0);
	}
}

