#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define PATH_MAX 4096

extern char **environ;

void handle_command(char *command, char *prog_name)
{
	pid_t pid;
	int status;
	char *argv[MAX_ARGS]; /* MAX_ARGS est maintenant défini */
	int argc = 0;
	char *token;
	char *full_path;

	/* Tokenize the command to split it into arguments */
	token = strtok(command, " \n");
	while (token != NULL && argc < MAX_ARGS - 1)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;

	if (argc == 0) /* No command to execute */
		return;

	/* Check if the command is a built-in command */
	if (is_builtin(argv[0]))
	{
		handle_builtins(argv[0], command);
	}
	else
	{
		full_path = find_executable(argv[0]);
		if (full_path == NULL)
		{
			/*command not found*/
			error_message(prog_name, argv[0], argc);
			return;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(full_path, argv, environ) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else if (pid < 0)
		{
			/* Error forking */
			perror("fork");
		}
		else
		{
			/* Parent process waits for the child to finish */
			wait(&status);
		}
		free(full_path);
	}
}
/**
 * find_executable - Finds the full path of an executable command.
 * @command: The command to find.
 *
 * Return: The full path to the command or NULL if not found.
 */
char *find_executable(char *command)
{
	char *path_copy;
	char *token;
	char *path = _getenv("PATH");

	if (path == NULL)
		return NULL;

	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return NULL;

	strcpy(path_copy, path);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[PATH_MAX];
		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return strdup(full_path);
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}
char *_getenv(const char *name)
{
	size_t name_len = strlen(name);
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return *env + name_len + 1; /* Retourne la valeur de la variable d'environnement */
		}
		env++;
	}

	return NULL; /* Variable d'environnement non trouvée */
}


