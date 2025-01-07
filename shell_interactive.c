#include "simple_shell.h"

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
		fflush(stdout);
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
