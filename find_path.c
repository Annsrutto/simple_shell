#include "shell.h"

/**
 * search_path_ - Check if the command is in the path directory.
 * @cmd: Command to be checked.
 * @envp: Environment variables.
 */
void search_path(char **cmd, char **envp)
{
	char *cmd_prefix, *cmd_path, *path_env;
	int idx, seg_start, is_last_seg;

	cmd_prefix = str_concat("/", cmd[0]);
	path_env = fetch_environment("PATH", envp);

	if (!path_env)
	{
		free(cmd_prefix);
		exit(0);
	}

	seg_start = idx = is_last_seg = 0;
	while (path_env[idx])
	{
		if (path_env[idx] == ':' || !path_env[idx + 1])
		{
			is_last_seg = !path_env[idx + 1];
			if (is_last_seg)
				idx++;

			cmd_path = str_concat(path_env + seg_start, cmd_prefix);

			if (access(cmd_path, F_OK) == 0)
			{
				free(cmd[0]);
				cmd[0] = cmd_path;
				free(cmd_prefix);
				return;
			}

			free(cmd_path);
			if (is_last_seg)
				break;

			seg_start = idx + 1;
		}
		idx++;
	}

	free(cmd_prefix);
}

