#include "header.h"

/**
 * handle_command - Handle external commands.
 * @command: The command to handle.
 * @prog_name: The name of the program (argv[0]).
 *
 * This function checks if the command is a built-in command and
 * processes it accordingly. If it is an external command, it
 * forks a new process to execute it.
 */
void handle_command(char *command)
{
	pid_t pid;
	int status;

	if (is_builtin(command))
	{
		handle_builtins(command);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			char *argv[2];
			argv[0] = command;
			argv[1] = NULL;

			if (execve(command, argv, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			wait(&status);
		}
	}
}
