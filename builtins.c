#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX 4096

int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return (1);
	}
	return (0);
}
void handle_builtins(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
}
/**
 * display_prompt - Displays the shell prompt
 *
 * Return: void
 */
void display_prompt(void)
{
	/* Display the prompt symbol */
	printf("$ ");
	fflush(stdout); /* Ensure the prompt is displayed */
}

void error_message(char *prog_name, char *command, int argc)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, argc, command);
}
/**
 * find_executable - Finds the full path of an executable command.
 * @command: The command to find.
 *
 * Return: The full path to the command or NULL if not found.
 */
char *find_executable(char *command)
{
	char *path_copy;
	char *token;

	char *path = getenv("PATH");
	if (path == NULL)
		return NULL;

	path_copy = strdup(path);
	if (path_copy == NULL)
		return NULL;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[PATH_MAX];
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

		printf("Trying path: %s\n", full_path); /*debugage*/
		
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return strdup(full_path);
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}

