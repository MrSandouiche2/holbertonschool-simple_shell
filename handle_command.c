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
void handle_command(char *command, char *prog_name)
{
	pid_t pid;
	int status;

	if (is_builtin(command))
	{
		handle_builtins(command);
	}
	else
	{
		/* Vérifier qu'il n'y a pas d'espaces dans la commande */
		if (strchr(command, ' ') != NULL)
		{
			printf("%s: Command should not contain any arguments.\n", prog_name);
			return; /* Ne pas exécuter la commande si des arguments sont présents */
		}

		pid = fork();
		if (pid == 0)
		{
			char *argv[2];
			char *envp[] = { NULL }; /* Passer un environnement vide */

			argv[0] = command; /* Commande unique sans arguments */
			argv[1] = NULL;

			execve(argv[0], argv, envp);
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, command);
			exit(1);
		}
		else if (pid < 0)
		{
			perror(prog_name);
		}
		else
		{
			wait(&status);
		}
	}
}

