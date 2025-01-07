#include "simple_shell.c"

/**
 * read_stream - read a line from the stream
 * Return: a pointer to the read line
 */
char *read_stream(void)
{
	int bufsize = 1024, i = 0, character;
	char *line = malloc(sizeof(char) * bufsize);

	if (line == NULL)
	{
		fprintf(stderr, "Allocation error in read_stream");
		exit(EXIT_FAILURE); }
	while (1)
	{
		character = getchar ();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS); }
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line); }
		else if (character != '\n' && character != EOF)
		{
			line[i] = character; }
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			if (line == NULL)
			{
				fprintf(stderr, "Reallocation error in read_stream");
				exit(EXIT_FAILURE); }
		}
	}
}
