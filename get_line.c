#include "shell.h"
/**
 * readLine - reads command line from terminal
 * Return: the line it readed
 */
char *readLine(void)
{
	static char buffer[BUFFER_SIZE];
	int position = 0;
	int bytesRead = 0;
	char *line = NULL;
	int lineLength = 0;

	while (1)
	{
		if (position >= bytesRead)
		{
			position = 0;
			bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytesRead == 0)
				return (NULL);
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
				return (line);
			}
			else
			{
				line = realloc(line, (lineLength + 2) * sizeof(char));
				line[lineLength++] = currentChar;
			}
		}
	}
}
