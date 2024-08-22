#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>

/**
 * tokenize_command - Tokenizes the command into arguments.
 * @command: The command to be tokenized.
 * @argv: Array to store the tokenized arguments.
 *
 * Return: The number of arguments tokenized.
 */
int tokenize_command(char *command, char *argv[])
{
	char *token;
	int argc = 0;

	/* Tokenize the command to split it into arguments */
	token = strtok(command, " \n");
	while (token != NULL && argc < MAX_ARGS - 1)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;

	return (argc);
}

/**
 * execute_external_command - Executes an external command.
 * @argv: Array of command arguments.
 * @prog_name: The name of the program (for error messages).
 */
void execute_external_command(char *argv[], char *prog_name)
{
	pid_t pid;
	int status;
	char *full_path;

	full_path = find_executable(argv[0]);
	if (full_path == NULL)
	{
		/* Command not found */
		error_message(prog_name, argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
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

/**
 * handle_command - Processes and executes a command.
 * @command: The command to be executed.
 * @prog_name: The name of the program (for error messages).
 */
void handle_command(char *command, char *prog_name)
{
	char *argv[MAX_ARGS]; /* Array for command arguments */
	int argc;

	argc = tokenize_command(command, argv);

	if (argc == 0) /* No command to execute */
		return;

	/* Check if the command is a built-in command */
	if (is_builtin(argv[0]))
	{
		handle_builtins(argv[0], command);
	}
	else
	{
		execute_external_command(argv, prog_name);
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
		return (NULL);

	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (NULL);

	strcpy(path_copy, path);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[PATH_MAX];

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * _getenv - Custom implementation of getenv.
 * @name: The name of the environment variable to get.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name)
{
	size_t name_len = strlen(name);
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
		env++;
	}

	return (NULL); /* Environment variable not found */
}



