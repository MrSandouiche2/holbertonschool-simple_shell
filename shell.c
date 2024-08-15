#include "header.h"

/**
 * prompt - Display the shell prompt and handle input.
 */
void prompt(void)
{
	char *command = NULL; /* Initialise la commande */

	while (1)
	{
		printf("($) "); /* Affiche le prompt */

		command = get_input(); /* Appel à get_input ici */

		if (command == NULL)
		{
			if (feof(stdin)) /* Vérifie si EOF (Ctrl+D) est pressé */
			{
				printf("\n");
				free(command);
				exit(0);
			}
			perror("getline");
			continue;
		}

		/* Supprimer le saut de ligne à la fin */
		command[strcspn(command, "\n")] = 0;

		if (strlen(command) > 0)
		{
			handle_builtins(command); /* Vérifier les commandes intégrées */
		}

		free(command); /* Libérer la mémoire ici pour éviter les fuites */
	}
}



