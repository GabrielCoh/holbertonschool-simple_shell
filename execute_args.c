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

/**
 * execute_args - check if the command is a builtin or a process
 * @args: the command line
 * Return: 1 on sucess or 0
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};

	unsigned long int x = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (; x < sizeof(builtin_func_list) / sizeof(char *); x++)
	{
		if (strcmp(args[0], builtin_func_list[x]) == 0)
		{
			return ((builtin_func[x])(args));
		}
	}
	return (new_process(args));
}
