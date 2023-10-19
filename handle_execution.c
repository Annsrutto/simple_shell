#include "shell.h"

/**
 * handle_execution - handles the execution of commands
 * @executable_path: Path of the executable
 * @args: List of parsed arguments
 * @env_vars: Environment variables
 *
 * Return: Nothing
 */
void handle_execution(char *executable_path, char **args, char **env_vars)
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

