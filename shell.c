#include "shell.h"

/**
 * main - Entry point of the program
 * @args_count: The number of arguments passed.
 * @args_list: The list of arguments.
 * @env_list: The list of environment variables.
 * Return: 0 (Success)
 */
int main(int args_count, char **args_list, char **env_list)
{
	char *prompt_text = "$ ";
	char *input_text = NULL;
	size_t buffer_len = 0;
	char *cmd_args[64];
	int is_interactive_mode;
	/*int index_count;*/
	ssize_t read_status;
	(void)args_count;
	(void)args_list;
	is_interactive_mode = check_interactive();

	while (1)
	{
		if (is_interactive_mode && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt_text, str_len(prompt_text));
		read_status = getline(&input_text, &buffer_len, stdin);

		if (read_status == -1)
		{
			if (feof(stdin))
			{
				if (is_interactive_mode && isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "\n", 1);
				free(input_text);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Input read error");
				free(input_text);
				exit(EXIT_FAILURE);
			}
		}
		if (str_len(input_text) > 1)
		{
			input_text[str_exclude_span(input_text, "\n")] = 0;
			process_input(input_text, cmd_args, env_list);
		}
	}
	free(input_text);
	return (0);
}

