#include "shell.h"
/**
 * execute_command - executes commands
 * @args: arguments
 * Return: void
 */
void execute_command(char* command)
{
	pid_t pid;
	char *args[MAX_ARGUMENTS];
	int i = 0;
	char *token = strtok(command, " ");
	int status;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
}
