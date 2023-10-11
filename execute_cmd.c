#include "shell.h"

/*
* execute_command - Executes a given command.
* @cmd: The command to execute.
* @argv: Argument vector.
* Return: 0 on success, -1 on failure.
*/

int execute_command(char *cmd, char **argv)
{
	pid_t child_pid;
	int status;

	/* Forking to create a child process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv[0]);
		return (-1);
	}

	/* Child process */
	if (child_pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			return (-1);
		}
	}
	/* Parent process */
	else
	{
		wait(&status);
	}

	return (0);
}
