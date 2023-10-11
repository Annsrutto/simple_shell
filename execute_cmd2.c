#include "shell.h"

/*
* execute_command - Executes a given command.
* @tokens: The command and its arguments.
* Return: 0 on success, -1 on failure.
*/
int execute_command2(char **tokens)
{
	pid_t child_pid;
	int status;

	/* Forking to create a child process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(tokens[0]);
		return (-1);
	}

	/* Child process */
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
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
