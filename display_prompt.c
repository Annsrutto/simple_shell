#include "shell.h"

/**
 * display_prompt - Show command prompt to user and collect commands.
 * @ptr: Holds the user's input.
 * Return: 1 on success, -1 otherwise.
 */

int display_prompt(char **ptr)
{
	size_t buffer_size = 0;
	int read_status;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	read_status = getline(ptr, &buffer_size, stdin);

	if (read_status == EOF)

		free_strings(-1, 1, *ptr);

	(*ptr)[read_status - 1] = '\0';

	if (*(*ptr) == '\0' || (*(*ptr) == '.' && (*ptr)[1] == '\0'))
	{
		free_strings(99, 1, *ptr);
		return (-1);
	}
	else
		return (1);
}
