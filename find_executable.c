#include "simple_shell.h"

/**
 * find_executable - search for the full path of the executable
 * @command: command to the path
 * Return: the full path or NULL
 */

char *find_executable(char *command)
{
	extern char **environ;
	char *path_env = NULL;
	char *path_copy, *dir, *full_path;
	int x = 0, len;

	while (environ[x] != NULL && path_env == NULL)
	{
		if (strncmp(environ[x], "PATH=", 5) == 0)
		{
			path_env = environ[x] + 5;
		}
		x++;
	}
	path_copy = strdup(path_env);
	if (path_copy == NULL || command == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
