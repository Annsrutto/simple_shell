#include "shell.h"

/**
 * process_setenv - Initialize a new environment variable.
 * @variable_name: The name of the variable.
 * @variable_value: The value assigned to the name variable.
 *
 * Return: -1 on error, 0 on success.
 */
int process_setenv(char *variable_name, char *variable_value)
{
	char error_msg[] = "Failed to set environment variable.\n";

	if (setenv(variable_name, variable_value, 1) == 0)
	{
		return (0);
	}
	else
	{
		write(STDERR_FILENO, error_msg, str_length(error_msg));
		return (-1);
	}
}

/**
 * process_unsetenv - Remove an environment variable.
 * @variable_name: The name of the variable.
 *
 * Return: -1 on error, 0 on success.
 */
int process_unsetenv(char *variable_name)
{
	char error_msg[] = "Failed to unset environment variable.\n";

	if (unsetenv(variable_name) == 0)
	{
		return (0);
	}
	else
	{
		write(STDERR_FILENO, error_msg, str_length(error_msg));
		return (-1);
	}
}

