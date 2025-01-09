#include "simple_shell.h"

/**
 * main - function that checks if our shell is called
 * Return: 0 on success
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}
	else
	{
		shell_no_interactive();
	}
	return (-1);
}

/**
 * shell_interactive - Function that display the prompt,
 * and interpret commands
 */

void shell_interactive(void)
{
	char *line = NULL;
	char **args;
	int status = -1;

	do {
		write(1, "$ ", 2);
		line = read_line();
		args = split_line(line);
		status = execute_args(args);
		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}

/**
 * shell_no_interactive - unix command line interpreter
 * Return: void
 */

void shell_no_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_stream();
		args = split_line(line);
		status = execute_args(args);
		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
