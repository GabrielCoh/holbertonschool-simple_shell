#include "simple_shell.h"

/**
 * split_line - Function that split a string
 * @line: the string to be splited
 * Return: a pointer to the new array
 */

char **split_line(char *line)
{
	int bufsize = 64;
	int new_bufsize;
	int x = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));
	char **new_tokens;

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
			break;
		}
		tokens[x] = token;
		x++;
		if (x >= bufsize)
		{
			new_bufsize = bufsize * 2;
			new_tokens = malloc(new_bufsize * sizeof(char *));
			if (new_tokens == NULL)
			{
				fprintf(stderr, "allocation error in split_line: new_tokens");
				free(tokens);
				exit(EXIT_FAILURE);
			}
			memcpy(new_tokens, tokens, bufsize * sizeof(char *));
			free(tokens);
			tokens = new_tokens;
			bufsize = new_bufsize;
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[x] = NULL;
	return (tokens);
}
