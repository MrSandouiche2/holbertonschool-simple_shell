#include "header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* Dans la fonction handle_command, remplacer execvp par execve */
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
		/* Vérifier qu'il n'y a pas d'espaces dans la commande */
		if (strchr(command, ' ') != NULL)
		{
			printf("Error: Command should not contain any arguments.\n");
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
			perror(argv[0]);
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
