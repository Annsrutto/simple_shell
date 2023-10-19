#include "shell.h"

/**
 * display_exit_error - Print an error message and then exit.
 * @argv: argument vector.
 * @status: exit status.
 */
void display_exit_error(char *argv, int status)
{
	(void)status;
	perror(argv);
	exit(0);
}

/**
 * handle_exit_command - Process the exit command.
 * @args: Provided command arguments.
 * @envp: Environment variables.
 * Return: 1 on success.
 */
int handle_exit_command(char **args, char **envp)
{
	int exit_status;
	(void)envp;

	exit_status = 0;
	if (args[1])
		exit_status = _atoi(args[1]);
	free_command_list(args);
	exit(exit_status);
}

