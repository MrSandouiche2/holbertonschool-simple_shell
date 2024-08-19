#include "header.h"

/**
 * prompt - Display the shell prompt and handle input.
 * @prog_name: The name of the program (argv[0]).
 */
void prompt(char *prog_name)
{
	char *command = NULL; /* Initialise la commande */

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			printf("($) "); /* Affiche le prompt */
		}

		command = get_input(); /* Appel à get_input ici */

		if (command == NULL)
		{
			if (feof(stdin)) /* Vérifie si EOF (Ctrl+D) est pressé */
			{
				printf("\n");
				free(command);
				exit(0);
			}
			perror(prog_name); /* Utiliser prog_name pour l'affichage des erreurs */
			continue;
		}

		/* Supprimer le saut de ligne à la fin */
		command[strcspn(command, "\n")] = 0;

		if (strlen(command) > 0)
		{
			handle_command(command, prog_name); /* Gère la commande */
		}

		free(command); /* Libérer la mémoire ici pour éviter les fuites */
	}
}




