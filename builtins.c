#include "header.h"

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
