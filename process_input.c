#include "shell.h"

/**
 * process_input - Parse and execute commands from the user.
 * @input_str: String of user input.
 * @parsed_args: Array to store parsed arguments.
 * @env_vars: Array of environment variables.
 */
void process_input(char *input_str, char **parsed_args, char **env_vars)
{
	int index = 0;
	char *segment;

	input_str[str_exclude_span(input_str, "\n")] = 0;

	if (input_str == NULL || input_str[0] == '\0' ||
		str_span(input_str, " ") == str_len(input_str))
		return;

	segment = strtok(input_str, " ");
	while (segment != NULL)
	{
		parsed_args[index++] = segment;
		segment = strtok(NULL, " ");
	}

	parsed_args[index] = NULL;

	if (str_compare(parsed_args[0], "exit") == 0)
	{
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
	{
		if (index > 0)
			run_command(parsed_args, env_vars);
	}
}

