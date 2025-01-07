#include "simple_shell.h"

/**
 * own_help - prints help
 * @args: argument
 * Return: -1
 */

int own_help(char **args)
{
	char *builtin_args[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	size_t i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_args) / sizeof(char *); i++)
	{
		printf(" -> %s\n", builtin_args[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}
