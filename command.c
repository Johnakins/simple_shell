#include "shell.h"
/**
 * execute_command - executes command for the shell
 * @command: command to be executed
 * Return: void
 */
void execute_command(char *const args[])
{
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
		execve(args[0], args, NULL);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
