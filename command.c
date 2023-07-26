#include "shell.h"
/**
 * execute_command - executes command for the shell
 * @command: command to be executed
 * Return: void
 */
void execute_command(char *command)
{
	char **args = (char **)malloc(2 * sizeof(char *));
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (!args)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		execve(command, args, NULL);
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
