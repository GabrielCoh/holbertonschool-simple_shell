#include "simple_shell.h"

/**
 * split_line - Function that split a string
 * @line: the string to be splited
 * Return: a pointer to the new array
 */

char **split_line(char *line)
{
	int bufsize = 64;
	int x = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (tokens == NULL)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			tokens[x] = NULL;
			return (tokens);
		}
		tokens[x] = token;
		x++;
		if (x >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (token == NULL)
			{
				fprintf(stderr, "reallocation error in split_line: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[x] = NULL;
	return (tokens);
}
