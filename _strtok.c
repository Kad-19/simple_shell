#include "shell.h"
/**
 * stringToken - a function that splits string to tokens
 * @input: The input string to be tokenized.
 * @command: Pointer to a character array to store the command token.
 * @arguments: Pointer to a character array to store the arguments token.
 * 
 * This function takes an input string and splits it into tokens, separating the command and arguments.
 * 
 * Return: error message
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
