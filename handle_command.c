#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void handle_command(char *command, char *prog_name)
{
	pid_t pid;
	int status;
	char *argv[MAX_ARGS]; /* MAX_ARGS est maintenant défini */
	int argc = 0;
	char *token;
	char *full_path;

	/* Tokenize the command to split it into arguments */
	token = strtok(command, " \n");
	while (token != NULL && argc < MAX_ARGS - 1)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;

	if (argc == 0) /* No command to execute */
		return;

	/* Check if the command is a built-in command */
	if (is_builtin(argv[0]))
	{
		handle_builtins(argv[0]);
	}
	else
	{
		full_path = find_executable(argv[0]);
		if (full_path == NULL)
		{
			/*command not found*/
			error_message(prog_name, argv[0], argc);
			return;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(full_path, argv, environ) == -1)
			{
				perror("execve");
				free(full_path);
				exit(1);
			}
		}
		else if (pid < 0)
		{
			/* Error forking */
			perror("fork");
		}
		else
		{
			/* Parent process waits for the child to finish */
			wait(&status);
		}
		free(full_path);
	}
}

