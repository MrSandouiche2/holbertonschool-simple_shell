#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void prompt(char *prog_name);
char *get_input(void);
void handle_command(char *command, char *prog_name);
void handle_builtins(char *command);
int is_builtin(char *command);

#endif /* HEADER_H */


