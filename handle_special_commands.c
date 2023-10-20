#include "shell.h"

/**
 * handle_special_commands - Handles special shell commands.
 * @args: Array of parsed arguments.
 * @envp: Array of environment variables.
 */
void handle_special_commands(char **args, char **envp)
{
	if (str_compare(args[0], "exit") == 0)
	{
		if (args[1])
		{
			int exit_code = _atoi(args[1]);

			exit(exit_code);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else if (str_compare(args[0], "setenv") == 0)
	{
		if (!args[1] || !args[2])
		{
			write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
			return;
		}
		process_setenv(args[1], args[2]);
	}
	else if (str_compare(args[0], "unsetenv") == 0)
	{
		if (!args[1])
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			return;
		}
		process_unsetenv(args[1]);
	}
	else if (str_compare(args[0], "env") == 0)
		display_environment(args, envp);
	else
		run_builtin_command(args, envp);
}

