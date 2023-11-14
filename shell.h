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

/********CONSTANTS*******/
#define BUFFER_SIZE 1024
#define MAX_INPUT_SIZE 1024

/******PROTOTYPES******/
void show_prompt(void);
void execute(const char *command);
void _print(char *format);
void _read(char *command, size_t size);
void shell_loop(void);
char read_line(void);
void string_token(const char *input, char *command, char *arguments);

#endif
