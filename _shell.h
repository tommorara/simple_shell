#ifndef _SHELL_H
#define _SHELL_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>
#include <ctype.h>

#define MAXIMUM_COMMAND_LENGTH 500
#define MAXIMUM_ARGUMENTS 50
#define MAXIMUM_COMMANDS 50
#define INITIAL_BUFFER_SIZE 128
#define MAX_BUFFER_SIZE 1024

extern char **environ;
extern char _current_directory[1024];
extern char *_previous_directory;
extern char home[1024];

/**
 * struct _built_in - structure of command and function
 * @com: command to be compared and function called
 * @func: function to be called when command matches
 */

typedef struct _built_in
{
	char *com;
	void (*func)(char **argv, char **env, char **tok_arr);
} _built_in;

char **process_entry(char **argv, int *mode);
char _putcharshell(const char *str);
void _show_prompt(void);
void _scan_command(char **_command);
void _free_replaced_var(char *_replaced);
void _free_commands(char *commands);

int _atoi(char *s);
int _isdigit(int c);

void _env_handler(char **argv, char **env, char **tok_arr);
void cd_handler(char **argv, char **env, char **tok_arr);
void exit_handler(char **argv, char **env, char **tok_arr);

char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _free_array_tokens(char **arr_tok);

extern int status;
extern int count_com;

char *obtain_path(char **env);
char **break_path(char *path_var);
char *locate_str(char *cmd, char *path);
char **break_user_entry(char *user_input);
void signal_handler(int signum);
int _builtins_handler(char **argv, char **env, char **token_arr);
int PATH_handler(char **argv, char **env, char **token_array, int *count_com);
void full_Path_handler(char **token_arr, char **env, char **argv, int mode);
void error_msg(int _fd, int num, char *s1, char *s2, char *s3);


int missing_path_handler(char *in_path, char **token_array,
		char **env, int *mode, int *cmd_count, char **argv);


void interactive_handler(char **argv, char **env, int *cmd_count, int *mode);

char **process_entry(char **argv, int *mode);
char _putcharshell(const char *str);
void _show_prompt(void);
void _scan_command(char **_command);
void _free_replaced_var(char *_replaced);
void _free_commands(char *commands);

#endif /*_SHELL_H */
