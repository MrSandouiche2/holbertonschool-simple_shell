#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Global environment variable */
extern char **environ;

/* Function prototypes */
void display_prompt(void);
void handle_command(char *command, char *prog_name);
void error_message(char *prog_name, char *command);

#endif /* HEADER_H */
