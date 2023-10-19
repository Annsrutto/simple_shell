#include "shell.h"
/**
 * main- Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: environment variables
 * Return: 0 upon success
 */
int main(int argc, char *argv[], char **envp)
{
	char *input = NULL;
	char **commands = NULL;
	int proc_status;
	pid_t child_pid;
	(void)argc;

	while (1)
	{
		input = NULL;
		signal(SIGINT, handle_signal);
		if (display_prompt(&input) == -1)
			continue;

		commands = str_tok(input);
		if (!commands)
		{
			free_strings(99, 1, input);
			continue;
		}
		free_strings(99, 1, input);

		if (run_builtin_command(commands, envp))
			continue;

		child_pid = fork();
		if (child_pid == 0)
		{
			search_path(commands, envp);
			if (execve(commands[0], commands, NULL) == -1)
			{
				perror(*argv);
				free_command_list(commands);
				exit(0);
			}
		}
		else
		{
			free_command_list(commands);
			if (!wait(&proc_status))
				break;
		}
	}
	return (0);
}
