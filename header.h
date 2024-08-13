#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void display_env(void);
void execute_command(char *command);
void prompt(void);
char *get_input(void);
void handle_builtins(char *command);

#endif /* HEADER_H */

