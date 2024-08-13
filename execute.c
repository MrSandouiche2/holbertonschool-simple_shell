#include "header.h"

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error:");
	}
	else if (pid == 0)
	{
		char *args[2];

		args[0] = command;/*Commande à exécuter*/
		args[1] = NULL;

		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");/*Afficher l'erreur*/
		}
		exit(0);/*Terminer le processus fils*/
	}
	else
	{
		wait(NULL);/*Attendre que le processus fils se termine*/
	}
}
