#include "header.h"

/**
 * display_env - Display the current environment variables.
 */
void display_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
/**
 * handle_builtins - Handle built-in commands.
 * @command: The command to execute.
 */
void handle_builtins(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
		display_env();
	}
	else
	{
		execute_command(command);
	}
}


