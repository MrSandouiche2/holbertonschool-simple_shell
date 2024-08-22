#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * is_builtin - Checks if a command is a built-in command.
 * @command: The command to check.
 *
 * Return: 1 if the command is a built-in command, otherwise 0.
 */
int is_builtin(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * handle_builtins - Executes built-in commands.
 * @command: The built-in command to execute.
 * @line: The input line that contains the command.
 *
 * Description: Frees the memory allocated for the input line and exits
 *              the program if the command is "exit".
 */
void handle_builtins(char *command, char *line)
{
	if (strcmp(command, "exit") == 0)
	{
		free(line);
		exit(0);
	}
}
/**
 * display_prompt - Displays the shell prompt.
 *
 * Description: Prints the prompt symbol ('$ ') and ensures that the prompt
 *              is displayed by flushing the output buffer.
 *
 * Return: void
 */
void display_prompt(void)
{
	/* Display the prompt symbol */
	printf("($) ");
	fflush(stdout); /* Ensure the prompt is displayed */
}
/**
 * error_message - Prints an error message when a command is not found.
 * @prog_name: The name of the program (for error messages).
 * @command: The command that was not found.
 * @argc: The argument count (for error message formatting).
 *
 * Description: Prints an error message to standard error indicating that
 *              the specified command was not found.
 *
 * Return: void
 */
void error_message(char *prog_name, char *command)
{
	fprintf(stderr, "%s: %s: not found\n", prog_name, command);
}
