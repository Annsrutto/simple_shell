#include "shell.h"

/**
 * display_environment - Prints the environment variables.
 * @args: Array of arguments.
 * @envp: List of environment variables.
 * Return: 1 on success.
 */
int display_environment(char **args, char **envp)
{
	int str_len, idx = 0;

	while (envp[idx])
	{
		str_len = str_length(envp[idx]);
		write(STDOUT_FILENO, envp[idx], str_len);
		write(STDOUT_FILENO, "\n", 1);
		idx++;
	}
	free_command_list(args);
	return (1);
}

