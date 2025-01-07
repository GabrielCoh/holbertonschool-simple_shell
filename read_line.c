#include "simple_shell.h"

/**
 * read_line - function that read a line from stdin
 * Return: line, the pointor to the string read
 */

char *read_line(void)
{
	char *line;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
