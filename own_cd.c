#include "simple_shell.h"

/**
 * own_cd - changes the current working directory
 * @args: target directory
 * Return: -1
 */

int own_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error in own_cd.c: changing directory\n");
		}
	}
	return (-1);
}
