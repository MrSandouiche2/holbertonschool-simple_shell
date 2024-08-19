#include "header.h"
#include <stdio.h>

void error_message(char *prog_name, char *command, int argc)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, argc, command);
}
