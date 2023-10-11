#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int execute_command(char *cmd, char **argv);
int execute_command2(char **tokens);
char **tokenize_input(char *line);

#endif
