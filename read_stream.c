#include "simple_shell.h"

/**
 * read_stream - read a line from the stream
 * Return: a pointer to the read line
 */
char *read_stream(void)
{
	int bufsize = 1024, i = 0, read_char, new_bufsize;
	char *line = malloc(sizeof(char) * bufsize), *new_line, character;

	if (line == NULL)
	{	fprintf(stderr, "Allocation error in read_stream");
		exit(EXIT_FAILURE); }
	while (1)
	{	read_char = read(STDIN_FILENO, &character, 1);
		if (read_char == -1)
		{	free(line);
			exit(EXIT_FAILURE);
		}
		if (read_char == 0)
		{       free(line);
			exit(EXIT_SUCCESS);
		}
		if (read_char == EOF)
		{	free(line);
			exit(EXIT_SUCCESS); }
		else if (character == '\n')
		{	line[i] = '\0';
			return (line); }
		line[i] = character;
		i++;
		if (i >= bufsize)
		{
			new_bufsize = bufsize * 2;
			new_line = malloc(new_bufsize * sizeof(char));
			if (new_line == NULL)
			{	fprintf(stderr, "allocation error in split_line: new_tokens");
				free(line);
				exit(EXIT_FAILURE); }
			memcpy(new_line, line, bufsize * sizeof(char));
			free(line);
			line = new_line;
			bufsize = new_bufsize;
		}
	}
}
