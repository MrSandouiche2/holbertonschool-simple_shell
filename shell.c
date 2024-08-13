#include "header.h"

/**
 * prompt - Display the shell prompt and handle input.
 */
void prompt(void)
{
	char *command = NULL; /*Initialise la commande*/
	size_t len = 0;/*Pour getline*/

	while (1)
	{
		printf("($) "); /*Affiche le prompt*/

		if (getline(&command, &len, stdin) == -1)
		{
			if (feof(stdin))
			{
				printf("\n"); /*Gérer l'entrée EOF (Ctrl+D)*/
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
			handle_builtins(command); /*Vérifier les commandes intégrées*/
			execute_command(command); /*Exécuter la commande*/
		}
	}

	free(command);
}


