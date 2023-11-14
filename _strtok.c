#include "shell.h"

void string_token(const char *input, char *command, char *arguments)
{
    int i = 0;
    int j = 0;

    while (input[i] != ' ' && input[i] != '\0')
    {
        command[j] = input[i];
        i++;
        j++;
    }
    command[j] = '\0';

    while (input[i] == ' ')
    {
        i++;
    }

    j = 0;

    while (input[i] != '\0')
    {
        arguments[j] = input[i];
        i++;
        j++;
    }
    arguments[j] = '\0';
}
