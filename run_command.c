#include "shell.h"

/**
 * run_command - executes commands based on user input
 * @args: List of parsed arguments from user input
 * @env_vars: Environment variables
 *
 * Return: Nothing
 */
void run_command(char **args, char **env_vars)
{
	char *input_command, *env_path, *executable_path;

	input_command = args[0];
	env_path = getenv("PATH_VAR");
	if (!env_path)
	{
		perror("PATH variable not set");
		return;
	}
	executable_path = locate_cmd_path(input_command, env_path);
	if (executable_path)
	{
		handle_execution(executable_path, args, env_vars);
	}
	else
	{
		write(2, input_command, str_len(input_command));
		write(2, ": unrecognized command\n", 23);
	}
}

