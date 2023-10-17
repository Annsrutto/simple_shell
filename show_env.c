#include "shell.h"

/**
 * show_environment - Displays the environment variables.
 * @env_vars: Array containing the environment variables.
 *
 * Return: None.
 */

void show_environment(char **env_vars)
{
	int index;

	for (index = 0; env_vars[index] != NULL; index++)
	{
		write(STDOUT_FILENO, env_vars[index], str_len(env_vars[index]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

