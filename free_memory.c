#include "shell.h"

/**
 * free_command_list - Free memory allocated for the command list.
 * @cmd_list: The command list to be freed.
 */
void free_command_list(char **cmd_list)
{
	int idx = 0;

	if (!cmd_list)
		exit(0);

	while (cmd_list[idx])
	{
		free(cmd_list[idx]);
		idx++;
	}
	free(cmd_list);
}

/**
 * free_strings - Free multiple string pointers.
 * @exit_status: If not 99, then exit after freeing.
 * @num_str: The number of string pointers.
 * ...: Variable number of string pointers.
 */
void free_strings(int exit_status, const unsigned int num_str, ...)
{
	unsigned int idx;
	va_list str_args;
	char *ptr;

	va_start(str_args, num_str);

	for (idx = 0; idx < num_str; idx++)
	{
		ptr = va_arg(str_args, char *);
		free(ptr);
	}

	va_end(str_args);

	if (exit_status == 99)
		return;
	exit(0);
}
