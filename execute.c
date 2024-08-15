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
		char *args[100];/*capacité de 100 arg max*/
		char *token = strtok(command, " ");
		int i = 0;

		/*remplir le tableau d arguments*/
		while (token != NULL && i < 99)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;/*le dernier element doit etre NULL pour execvp*/

		/*executer la commande avec execvp*/
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);/*Afficher l'erreur*/
			exit (127);
		}

		exit(0);/*Terminer le processus fils*/
	}
	else
	{
		wait(NULL);/*Attendre que le processus fils se termine*/
	}
}
