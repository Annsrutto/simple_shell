#include "shell.h"
/**
  * run_simple_command - function that executes single-word command
  * @command: command to be executed
  */

void run_simple_command(char *command)
{
	pid_t child_process;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	child_process = fork();
	if (child_process == -1)
	{
		perror("Child creation failed");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int process_status;

		waitpid(child_process, &process_status, 0);
	}
}

