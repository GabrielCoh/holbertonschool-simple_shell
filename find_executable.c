#include "simple_shell.h"

/**
 * find_executable - search for the full path of the executable
 * @command: command to the path
 * Return: the full path or NULL
 */

char *find_executable(char *command)
{
	char **environ;
	char *path = environ("PATH");
	char *dir = strtok(path, ":");
	char *full_path = malloc(1024);

	while (dir != NULL)
	{
		sprintf(full_path, 1024, "%s%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}
