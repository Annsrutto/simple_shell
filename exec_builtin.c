#include "shell.h"

/**
 * run_builtin_command - Executes the built-in commands.
 * @args: Array of command arguments.
 * @envp: Array of environment variables.
 * Return: 1 if executed successfully, 0 otherwise.
 */
int run_builtin_command(char **args, char **envp)
{
	list_t cmd_list[] = {
		{"env", display_environment},
		{"exit", handle_exit_command},
		{NULL, NULL}
	};

	int i;

	if (!args[0])
		return (0);

	for (i = 0; i < 2; i++)
	{
		if (str_compare(args[0], cmd_list[i].cmd_name) == 0)
		{
			return (cmd_list[i].fptr(args, envp));
		}
	}

	return (0);
}

