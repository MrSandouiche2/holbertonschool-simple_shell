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

	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			display_prompt();
			nread = getline(&line, &len, stdin);
			if (nread == -1)
			{
				break;
			}
			handle_command(line, argv[0]);
		}
	}
	else
	{
		while ((nread = getline(&line, &len, stdin)) != -1)
		{
			handle_command(line, argv[0]);
		}
	}
	free(line);
	return (0);
}
