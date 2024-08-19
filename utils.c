#include "header.h"

/**
 * error_message - Prints an error message
 * @prog_name: The name of the program (argv[0])
 * @command: The command that caused the error
 *
 * Return: void
 */
void error_message(char *prog_name, char *command)
{
	/* Print the error message to stderr */
	fprintf(stderr, "%s: %s: command not found\n", prog_name, command);
}

