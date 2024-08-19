#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

/**
 * prompt - Display the shell prompt and handle input.
 * @prog_name: The name of the program (argv[0]).
 */
void prompt(char *prog_name)
{
	char *command = NULL;
	size_t len = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			printf("(%s) ", prog_name);
		}

		if (getline(&command, &len, stdin) == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(command);
				exit(0);
			}
			perror("getline");
			continue;
		}

		command[strcspn(command, "\n")] = 0;

		if (strlen(command) > 0)
		{
			handle_command(command, prog_name);
		}

		free(command);
		command = NULL;
	}
}
