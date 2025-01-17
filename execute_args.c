#include "simple_shell.h"

/**
 * execute_args - check if the command is a builtin or a process
 * @args: the command line
 * Return: 1 on sucess or 0
 */

int execute_args(char **args)
{
	size_t x;

	char (*builtin_func_list[]) = {
		"cd",
		"env",
		"exit"
	};

	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_exit
	};

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (x = 0; x < sizeof(builtin_func_list) / sizeof(char *); x++)
	{
		if (strcmp(args[0], builtin_func_list[x]) == 0)
		{
			return ((builtin_func[x])(args));
		}
	}
	return (new_process(args));
}
