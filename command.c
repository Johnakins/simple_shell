#include "shell.h"
/**
 * execute_cmd - executes command for the shell
 * @argv: argument vector
 * Return: void
 */
void execute_cmd(char **argv)
{
	char *cmd = NULL;
	char *realcmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		realcmd = locate_cmd(cmd);

		if (execve(realcmd, argv, NULL) == -1)
		{
			perror("Error executing command");
		}
	}
}
