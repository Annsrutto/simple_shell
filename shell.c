#include "shell.h"

/**
 * main - Main entry point for the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */

/* Pointer to arrat of environment variables*/
extern char ** environ;

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **tokens;
	(void) argc; /* unused variable */

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		/* Handle end of file */
		if (read == -1)
		{
			printf("\n");
			free(line);
			exit(0);
		}

		/* Remove the newline character from the line */
		line[read - 1] = '\0';

		/* Tokenize the input*/
		tokens = tokenize_input(line);

		/* Check for the "exit" command */
		if (tokens[0] && strcmp(tokens[0],"exit") == 0)
		{
			free(line);
			free(tokens);
			exit(0);
		}

		/* Check for the "env" command */
		if (tokens[0] && strcmp(tokens[0], "env") == 0)
		{
			print_env();
			continue;
		}

		/* Execute the command */
		if (execute_command(line, argv) == -1)
		{
			perror(argv[0]);
		}
		
		if (execute_command2(tokens) == -1)
		{
			perror(tokens[0]);
		}

		free(line);
		line = NULL;
		free(tokens);
	}

	return (0);
}

/**
  * print_env - function that prints the environment variable
  */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}


