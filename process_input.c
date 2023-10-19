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
	{
		free(input_str);
		return;
	}

	segment = strtok(input_str, " ");
	while (segment != NULL)
	{
		parsed_args[index++] = segment;
		segment = strtok(NULL, " ");
	}
	parsed_args[index] = NULL;

	handle_special_commands(parsed_args, env_vars);
	free(input_str);
}

