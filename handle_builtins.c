#include "header.h"

void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0 ||
		strncmp(command, "cd", 2) == 0 || /* Utilisation de strncmp ici */
		strcmp(command, "env") == 0)
	{
		return (1); /* C'est un builtin */
	}
	return (0); /* Ce n'est pas un builtin */
}

void handle_builtins(char *command)
{
	char *path;

	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strncmp(command, "cd", 2) == 0) /* Correction avec strncmp */
	{
		path = strtok(command, " ");
		path = strtok(NULL, " ");
		if (path == NULL)
		{
			fprintf(stderr, "cd: missing operand\n");
			/* Correction de stdeer à stderr */
		}
		else if (chdir(path) != 0)
		{
			perror("cd failed");
		}
	}
	else if (strcmp(command, "env") == 0)
	{
		print_env(); /* Appelle la fonction pour afficher l'environnement */
	}
}
