#include "header.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	/* Suppression du warning pour un paramètre non utilisé */
	(void)argc;

	while (1)
	{
		/* Display the prompt */
		display_prompt();

		/* Read a line from standard input */
		nread = getline(&line, &len, stdin);
		if (nread == -1) /* EOF condition (Ctrl+D) or error */
		{
			if (line) /* Free allocated memory if any */
				free(line);

			if (nread == -1 && line == NULL) /* End of file reached */
				exit(0); /* Normal exit */
			else
			{
				perror("getline");
				exit(1);
			}
		}

		/* Handle the command */
		handle_command(line, argv[0]);
	}

	free(line);
	return (0);
}

