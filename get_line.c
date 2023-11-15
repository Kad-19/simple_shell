#include "shell.h"
/**
 * readLine - Reads a line of input from the standard input.
 *
 * This function reads a line of input from the standard input, character by character,
 * until it encounters a newline character ('\n') or reaches the end of the input.
 * It dynamically allocates memory to store the input line and expands the memory as needed.
 *
 * Return: A pointer to a dynamically allocated string containing the input line,
 *         or NULL if there is no more input or an error occurs.
 *
 */
char *readLine(void)
{
    static char buffer[BUFFER_SIZE];
    static int position = 0;
    static int bytesRead = 0;

    char *line = NULL;
    int lineLength = 0;

    while (1)
    {
        if (position >= bytesRead)
        {
            position = 0;
            bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (bytesRead == 0)
                return NULL;
            if (bytesRead < 0)
            {
                perror("read error");
                exit(EXIT_FAILURE);
            }
        }

        while (position < bytesRead)
        {
            char currentChar = buffer[position++];
            if (currentChar == '\n')
            {
                line[lineLength] = '\0';
                return line;
            }
            else
            {
                line = realloc(line, (lineLength + 2) * sizeof(char));
                line[lineLength++] = currentChar;
            }
        }
    }
}
