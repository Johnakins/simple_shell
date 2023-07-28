#include "shell.h"
/**
 * execute_command - executes commands
 * @tok_cmd: the command
 * @typ_cmd: the program_name to be displayed
 * Return: void
 */
void execute_command(char **tok_cmd, int typ_cmd, char *shellname)
{
	void (*func)(char **cmd);

	if (typ_cmd == OUTTER_CMD)
	{
		if (execve(tok_cmd[0], tok_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (typ_cmd == PATH_CMD)
	{
		if (execve(path_check(tok_cmd[0]), tok_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (typ_cmd == INNER_CMD)
	{
		func = get_func(tok_cmd[0]);
		func(tok_cmd);
	}
	if (typ_cmd == INV_CMD)
	{
		_print(shellname, STDERR_FILENO);
		_print(": 1: ", STDERR_FILENO);
		_print(tok_cmd[0], STDERR_FILENO);
		_print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

