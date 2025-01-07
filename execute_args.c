#include "simple_shell.h"

/**
 * execute_args - check if the command is a builtin or a process
 * @args: the command line
 * Return: 1 on sucess or 0
 */

int execute_args(char **args)
{
	size_t x;

	builtin_t builtin_args[] = {
		{"cd", &own_cd},
		{"env", &own_env},
		{"help", &own_help},
		{"exit", &own_exit}
	};

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (x = 0; x < sizeof(builtin_args) / sizeof(builtin_t); x++)
	{
		if (strcmp(args[0], builtin_args->name) == 0)
		{
			return ((builtin_args[x]).func(args));
		}
	}
	return (new_process(args));
}
