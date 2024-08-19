#include "header.h"
/**
 * print_env - Print the current environment variables.
 *
 * This function iterates through the global environ variable
 * and prints each environment variable to stdout.
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
/**
 * is_builtin - Check if the command is a built-in command.
 * @command: The command to check.
 *
 * Return: 1 if it's a built-in command, 0 otherwise.
 */
int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0 ||
		strncmp(command, "cd", 2) == 0 ||
		strcmp(command, "env") == 0)
	{
		return (1);/*C'est un builtin*/
	}
	return (0);/*Ce n'est pas un builtin*/
}
/**
 * handle_builtins - Handle built-in commands.
 * @command: The command to handle.
 *
 * This function processes built-in commands like exit, cd, and env.
 */
void handle_builtins(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(command, "cd") == 0)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd failed");
		}
	}
	else if (strcmp(command, "env") == 0)
	{
		print_env(); /* Appelle la fonction pour afficher l'environnement */
	}
}

