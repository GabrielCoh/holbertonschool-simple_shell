#include "simple_shell.h"

/**
 * own_exit - causes normal process termination
 * @args: empty args
 * Return: 0 during termination
 */

int own_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}
