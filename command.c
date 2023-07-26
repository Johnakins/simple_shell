#include "shell.h"
/**
<<<<<<< HEAD
 * execute_cmd - executes command for the shell
 * @argv: argument vector
=======
 * execute_command - executes commands
 * @args: arguments
>>>>>>> 3db24d910b561f8d96bc87a709ed8d397a12203f
 * Return: void
 */
void execute_cmd(char **argv)
{
<<<<<<< HEAD
	char *cmd = NULL;
	char *realcmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		realcmd = locate_cmd(cmd);

		if (execve(realcmd, argv, NULL) == -1)
=======
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
>>>>>>> 3db24d910b561f8d96bc87a709ed8d397a12203f
		{
			perror("Error executing command");
		}
	}
<<<<<<< HEAD
=======
	else
	{
		waitpid(pid, &status, 0);
	}
>>>>>>> 3db24d910b561f8d96bc87a709ed8d397a12203f
}
