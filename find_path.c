#include "shell.h"

/**
 * locate_cmd_path - Identifies the path of an executable in SYSTEM_PATH.
 * @command: The command to execute.
 * @system_path: The original SYSTEM_PATH variable.
 * Return: The complete path to the executable
 */
char *locate_cmd_path(char *command, char *system_path)
{
	char *duplicated_path;
	char *segment;
	char *executable_path;
	struct stat file_stat;

	duplicated_path = str_duplicate(system_path);
	segment = strtok(duplicated_path, ":");

	while (segment != NULL)
	{
		executable_path = malloc(str_len(segment) + str_len(command) + 2);

		str_copy(executable_path, segment);
		str_concat(executable_path, "/");
		str_concat(executable_path, command);
		str_concat(executable_path, "\0");
		if (stat(executable_path, &file_stat) == 0)
		{
			free(duplicated_path);
			return (executable_path);
		}
		free(executable_path);
		segment = strtok(NULL, ":");
	}
	free(duplicated_path);

	if (stat(command, &file_stat) == 0)
	{
		return (str_duplicate(command));
	}
	return (NULL);
}

