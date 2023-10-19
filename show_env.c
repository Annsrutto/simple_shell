#include "shell.h"

/**
 * fetch_environment- Retrieve the value of a specified environment variable.
 * @variable_name: Name of the environment variable to retrieve.
 * @envp: List of all environment variables.
 * Return: Pointer to value of environment variable, or NULL if not found.
 */
char *fetch_environment(const char *variable_name, char **envp)
{
	int idx = 0, x = 0;
	int var_len, outcome;

	while (envp[idx] != NULL)
	{
		outcome = str_compare(variable_name, (const char *)envp[idx]);

		if (outcome == 1)
		{
			var_len = str_length(envp[idx]);

			while (envp[idx][x] != '=')
				x++;
			var_len -= x;
			return (envp[idx] + x + 1);
		}
		idx++;
	}
	return (NULL);
}

