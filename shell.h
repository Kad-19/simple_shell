#ifndef SHELL_H
#define SHELL_H

/*******LIBRARIES*******/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/********CONSTANTS*******/
#define BUFFER_SIZE 1024
#define MAX_INPUT_SIZE 1024

/********Structures*****/
extern char **environ;


/**
 * struct shell_data - struct with shell atributes
 * @command: command line 
 * @pid: process ID of the shell
 * @av: argument vector
 * @counter: number of lines
 * @status: last status of the shell
 * @envir: environment variables
 * @args: tokens of the command line
 */
typedef struct shell_data
{
	char *command;
	char *pid;
	char **av;
	int counter;
	int status;
 	char **envir;
	char **args;
	
} shell_dat;

/**
 * struct builtins - struct for builtin command arguments
 * @command: The name of the command builtin i.e cd, exit, env
 * @call: data type pointer function.
 */
typedef struct builtins
{
	char *command;
	int (*call)(shell_dat *datash);
} builtin_li;

/******PROTOTYPES******/
void show_prompt(void);
void execute(const char *command);
void _print(char *format);
void _read(char *command, size_t size);
void shell_loop(void);
void handle_interruption(int sigint);
char *read_line(void);
void string_token(const char *input, char *command, char *arguments);

int handle_error(shell_dat *data, int err);
void freedat(shell_dat *dat);
void setdat(shell_dat *dat, char **av);

char *cd_error(shell_dat *dat, char *msg, char *error, char *str);
char *error_get_cd(shell_dat *dat);
char *exit_error(shell_dat *dat);
char *cmd_not_found_error(shell_dat *dat);
char *env_error(shell_dat *dat);
char *error_126(shell_dat *dat);

int _exit_shell(shell_dat *dat);
int (*set_builtin(char *input))(shell_dat *);
int print_env(shell_dat *dat);
char *_getenv(const char *name, char **_environ);
int cmp_env_name(const char *nenv, const char *name);

int exec_line(shell_dat *dat);

int _atoi(char *s);
char *aux_itoa(int n);
int _isdigit(const char *s);
int get_len(int n);

int cmd_exec(shell_dat *datash);
int check_error_cmd(char *dir, shell_dat *datash);
int is_executable(shell_dat *datash);
char *_which(char *cmd, char **_environ);
int is_cdir(char *path, int *i);

#endif
