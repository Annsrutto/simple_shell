#include "shell.h"

/**
 * handle_special_commands - Handles special shell commands.
 * @parsed_args: Array of parsed arguments.
 * @env_vars: Array of environment variables.
 */
void handle_special_commands(char **parsed_args, char **env_vars)
{
	if (str_compare(parsed_args[0], "exit") == 0)
	{
		if (parsed_args[1])
		{
			int exit_code = _atoi(parsed_args[1]);

			exit(exit_code);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else if (str_compare(parsed_args[0], "setenv") == 0)
	{
		if (!parsed_args[1] || !parsed_args[2])
		{
			write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
			return;
		}
		process_setenv(parsed_args[1], parsed_args[2]);
	}
	else if (str_compare(parsed_args[0], "unsetenv") == 0)
	{
		if (!parsed_args[1])
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			return;
		}
		process_unsetenv(parsed_args[1]);
	}
	else if (str_compare(parsed_args[0], "env") == 0)
		show_environment(env_vars);
	else
		run_command(parsed_args, env_vars);
}

