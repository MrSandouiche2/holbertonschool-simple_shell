#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * handle_command - Handles the execution of a command
 * @command: The command to execute
 * @prog_name: The name of the program (argv[0])
 *
 * Return: void
 */
void handle_command(char *command, char *prog_name)
{
	pid_t pid;
	int status;
	char *argv[2];

	/* Remove the newline character from the command */
	command[strcspn(command, "\n")] = '\0';

	/* Check if the command is executable */
	if (access(command, X_OK) == -1)
	{
		fprintf(stderr, "%s: %s: command not found\n", prog_name, command);
		return;
	}

	/* Create a child process */
	pid = fork();
	if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;

		/* Execute the command */
		execve(argv[0], argv, environ);
		perror("execve");
		exit(1);
	}
	else if (pid < 0)
	{
		/* Error handling for fork failure */
		perror("fork");
	}
	else
	{
		/* Wait for the child process to finish */
		wait(&status);
	}
}

