#include "shell.h"
/**
 * execute_command - executes commands
 * @args: arguments
 * Return: void
 */
void execute_command(char* command, char* program_name)
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
		fprintf(stderr, "%s: fork: unable to create a new process\n", program_name);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		fprintf(stderr, "%s: %s: command not found\n", program_name, args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			fprintf(stderr, "%s: waitpid: error while waiting for chld process\n", program_name);
		}
	}
}
