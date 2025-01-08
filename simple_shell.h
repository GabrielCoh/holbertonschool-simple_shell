#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

void shell_interactive(void);
void shell_no_interactive(void);

char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
extern char **environ;
char *find_executable(char *command);

char *read_stream(void);

/**
 * struct builtin - Check the command and if it is a build-in or not
 * @name: the command name
 * @func: the checking function
 */

typedef struct builtin
{
	char *name;
	int (*func)(char **);
} builtin_t;

int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

#endif
