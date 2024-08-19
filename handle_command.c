#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_command(char *command, char *prog_name)
{
	pid_t pid;
	int status;
	char *argv[2];  /* Déclare le tableau argv ici pour respecter les règles du C90 */

	(void)prog_name;  /* Supprime cet avertissement si prog_name n'est pas utilisé */

	if (is_builtin(command))
	{
		handle_builtins(command);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			argv[0] = command;  /* Initialisation du tableau argv après sa déclaration */
			argv[1] = NULL;

			execve(argv[0], argv, environ);
			perror("execve");
			exit(1);
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

