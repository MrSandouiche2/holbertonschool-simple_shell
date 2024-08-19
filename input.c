#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "header.h"


/**
 * get_input - Get command input from the user.
 * Return: The command entered by the user.
 */
char *get_input(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}

	return (buffer);
}
