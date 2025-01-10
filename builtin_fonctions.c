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

/**
 * own_env - function that prints environment variables
 * @args: arguments
 * Return: -1
 */

int own_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}

/**
 * own_cd - changes the current working directory
 * @args: target directory
 * Return: -1
 */

int own_cd(char **args)
{
	char *home = NULL, *oldpwd = NULL, *new_dir = NULL, current_dir[1024];
	int x;

	for (x = 0; environ[x]; x++) {
		if (strncmp(environ[x], "HOME=", 5) == 0) {
			home = environ[x] + 5;
		}
		if (strncmp(environ[x], "OLDPWD=", 7) == 0) {
			oldpwd = environ[x] + 7;
		}
	}

	if (args[1] == NULL) {
		if (home == NULL) {
			fprintf(stderr, "cd: HOME not set\n");
			return (-1);
		}
	} else if (strcmp(args[1], "-") == 0) {
		if (oldpwd == NULL) {
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (-1);
		}
		new_dir = oldpwd;
		printf("%s\n", oldpwd);
	} else {
		new_dir = args[1];
	}


	if (getcwd(current_dir, sizeof(current_dir)) != NULL) {
		setenv("OLDPWD", current_dir, 1);
	}

	if (chdir(new_dir) != 0) {
		perror("");
		return (-1);
	}

	if (getcwd(current_dir, sizeof(current_dir)) != NULL) {
		setenv("PWD", current_dir, 1);
	}
	return (-1);
}
