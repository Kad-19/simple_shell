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
/**
 * struct separators - list
 * @separator: & ; |
 * @next: next node pointer
 * Description: a list to store separators
 */
typedef struct separators
{
	char separator;
	struct separators *next;
} sep;

/**
 * struct lines - list of line
 * @line: command line
 * @next: next node pointer
 * Description: a list to store command lines
 */
typedef struct lines
{
	char *line;
	struct lines *next;
} line_li;

/******PROTOTYPES******/
void show_prompt(void);
void execute(const char *command);
void _print(char *format);
void _read(char *command, size_t size);
void shell_loop(shell_dat *dat);
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
char *get_env(const char *name, char **envir);
int env_namecmp(const char *env_name, const char *name);

int exec_line(shell_dat *dat);

int conv_atoi(char *s);
char *conv_itoa(int num);
int is_digit(const char *str);
int dig_len(int n);

int inp_exec(shell_dat *dat);
int check_err_inp(char *dir, shell_dat *dat);
int is_exec(shell_dat *dat);
char *_which(char *inp, char **_environ);
int in_cdir(char *p, int *i);

char **split(char *command);
int split_commands(shell_dat *dat, char *command);
void go_to_next(sep **list_s, line_li **list_l, shell_dat *dat);
void addnew(sep **start_s, line_li **start_l, char *command);
char *swapch(char *command, int bl);

char **_reallocdp(char **ptr, unsigned int size_o, unsigned int size_new);

sep *add_node_end_sept(sep **start, char sepr);
void sep_free(sep **start);
line_li *add_node_end_ln(line_li **start, char *line);
void line_free(line_li **start);

char *read_cmd(int *eof_j);

char *copy_dat(char *name, char *value);
void set_env_val(char *name, char *value, shell_dat *dat);
int _setenv_cmp(shell_dat *dat);
int _unsetenv(shell_dat *dat);
char *remove_comment(char *in);
void *_realloc(void *ptr, unsigned int size_o, unsigned int size_new);
#endif
