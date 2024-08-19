#include "header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_command(char *command, char *prog_name)
{
	(void)prog_name;
	pid_t pid;
	int status;

	if (is_builtin(command))
	{
		handle_builtins(command);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			char *argv[] = {command, NULL};
			execve(argv[0], argv, environ);
			perror("execve");
			exit(1);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			wait(&status);
		}
	}
}
