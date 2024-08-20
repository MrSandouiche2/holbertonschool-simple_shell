#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return (1);
	}
	return (0);
}
void handle_builtins(char *command, char *line)
{
	if (strcmp(command, "exit") == 0)
	{
		free(line);
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
