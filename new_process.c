#include "simple_shell.h"

/**
 * new_process - Function that create a new process
 * @args: array of trings that contains the commands lines
 * Return: 1 if succes or 0
 */

int new_process(char **args)
{
	pid_t pid;
	int status;
	char *path;

	pid = fork();
	if (pid == 0)
	{
		path = find_executable(args[0]);
		if (path == NULL)
		{
			perror("error in new_process: command not found");
			exit(EXIT_FAILURE);
		}
		if (execve(path, args, environ) == -1)
		{
			perror("error in new_process : execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("error in new_process : forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
