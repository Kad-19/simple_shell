#include "shell.h"

/**
 * stringToken - A function that splits a string into tokens.
 * @input: The input string to be tokenized.
 * @command: Pointer to a character array to store the command token.
 * @arguments: Pointer to a character array to store the arguments token.
 *
 * This function splits an input string into tokens,
 * separating the command and arguments.
 *
 * Return: None.
 */
void stringToken(const char *input, char *command, char *arguments)
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
