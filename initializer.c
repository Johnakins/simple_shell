#include "shell.h"
/**
 * ini_tializer - starts executing everything
 * @current_command: check current command
 * @typ_command:  parse the token
 * Return: void
 */
void ini_tializer(char **current_command, int typ_command, char *shellname)
{
	pid_t PID;

	if (typ_command == OUTTER_CMD || typ_command == PATH_CMD)
	{
		PID = fork();
		if (PID == 0)
		{
			execute_command(current_command, typ_command, shellname);
		}
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
	{
		execute_command(current_command, typ_command, shellname);
	}
}
