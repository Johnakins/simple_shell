#include "shell.h"
/**
 * execute_command - executes command for the shell
 * @args: command to be executed
 * Return: void
 */
void execute_command(char *const args[])
{
	pid_t child_pid;
	int status;

	if (args[0] == NULL)
	{
		return;
	}
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
