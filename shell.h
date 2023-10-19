#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>

extern char **environ;
int main(int argc, char *argv[], char **envp);
int display_prompt(char **command_str);
void handle_signal(int signal_number);
int run_builtin_command(char **args, char **envp);
char *fetch_environment(const char *variable_name, char **envp);
int display_environment(char **args, char **envp);
void display_exit_error(char *argv, int status);
int handle_exit_command(char **args, char **envp);
void search_path(char **cmd, char **envp);
void free_command_list(char **cmd_list);
void free_strings(int exit_status, const unsigned int num_strings, ...);
int _atoi(char *str);
char **str_tok(char *str);
void copy_word(int dest_len, char *src, char **dest);
char *str_concat(char *str1, char *str2);
int str_compare(const char *str1, const char *str2);
int str_n_compare(const char *str1, const char *str2);
int str_length(const char *str);
void copy_substring_to_array(int len, char *substr, char **dest);
void str_extract(char **word_array, char *str);
/**
  * struct builtin_cmd - contains builtin command and functions for shell
  * @cmd_name: name of command
  * @fptr: pointer to builtin fucntions
  *
  *Description: struct for builtin functions
  */
typedef struct builtin_cmd
{
	char *cmd_name;
	int (*fptr)(char **args, char **envp);

} list_t;

#endif

