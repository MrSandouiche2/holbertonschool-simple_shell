#include "header.h"

/**
 * handle_command - Handle external commands.
 * @command: The command to handle.
 *
 * This function checks if the command is a built-in command and
 * processes it accordingly. If it is an external command, it
 * forks a new process to execute it.
 */
void handle_command(char *command)
{
	if (is_builtin(command))
	{
		handle_builtins(command);
	}
	else
	{
		pid_t pid;
		int status;

		pid = fork();/*Déplace l'affectation hors du if*/
		if (pid == 0)
		{
			char *argv[4];

			argv[0] = "/bin/sh";
			argv[1] = "-c";
			argv[2] = command;
			argv[3] = NULL;

			execvp(argv[0], argv);
			perror("Command not found");
			exit(1);
		}
		else if (pid < 0)
		{
			perror("Fork failed");
		}
		else
		{
			wait(&status);
		}
	}
}


