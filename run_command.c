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
		pid_t child_process = fork();

		if (child_process == -1)
		{
			perror("Child creation failed");
			exit(EXIT_FAILURE);
		}
		else if (child_process == 0)
		{
			if (execve(executable_path, args, env_vars) == -1)
			{
				perror("Command execution failed");
				exit(EXIT_FAILURE);
			}
			free(executable_path);
		}
		else
		{
			int process_status;
			waitpid(child_process, &process_status, 0);

			if (WIFEXITED(process_status))
			{
				int termination_code = WEXITSTATUS(process_status);
				exit(termination_code);
			}
			else
				exit(EXIT_FAILURE);
			free(executable_path);
		}
	}
	else
	{
		write(2, input_command, str_len(input_command));
		write(2, ": unrecognized command\n", 23);
	}
}

