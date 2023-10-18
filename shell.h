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

void run_simple_command(char *command);
void run_command(char **args, char **env_vars);
char *locate_cmd_path(char *command, char *system_path);
int check_interactive(void);
/*ssize_t get_line_content(char **line_content_ptr, size_t *line_length, FILE *input_stream);*/
/*void initialize_buffer(char **line_content_ptr, size_t *line_length);*/
/*void expand_buffer(char **line_content_ptr, size_t *line_length, size_t index);*/
/*char *split_string(char *main_string, const char *delimiter);*/
char *get_environment_variable(const char *variable_name);
/*char *convert_str_to_lowercase(const char *main_string);*/
int process_unsetenv(char *variable_name);
int process_setenv(char *variable_name, char *variable_value);
void process_input(char *input_str, char **parsed_args, char **env_vars);
void show_environment(char **env_vars);

/* String utility functions */
size_t str_len(char *str);
char *str_copy(char *dest, char *source);
char *str_concat(char *dest, char *source);
int str_compare(char *str1, char *str2);
int str_exclude_span(char *str1, char *str2);
char *str_duplicate(const char *str);
char *str_char_search(const char *str, char ctr);
int str_compare_n(const char *str1, const char *str2, size_t count);
int _atoi(char *str);
size_t str_span(const char *str1, const char *str2);

#endif

