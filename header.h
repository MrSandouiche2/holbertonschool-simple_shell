#ifndef HEADER_H
#define HEADER_H
#define MAX_ARGS 10  /* Remplace 10 par le nombre maximum d'arguments que tu souhaites autoriser */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Global environment variable */
extern char **environ;

/* Function prototypes */
void display_prompt(void);
void handle_command(char *command, char *prog_name);
void error_message(char *prog_name, char *command, int argc);
int is_builtin(char *command);
void handle_builtins(char *command);
char *find_executable(char *command);

#endif /* HEADER_H */
