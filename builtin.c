#include "shell.h"
/**
 * env - displays environment
 * @tok_cmd: the command
 * Return: void
 */
void env(char **tok_cmd __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_print(environ[i], STDOUT_FILENO);
		_print("\n", STDOUT_FILENO);
	}
}
/**
 * quit - exits the shell
 * @tok_cmd: command entered
 * Return: void
 */
void quit(char **tok_cmd)
{
	int ntoken = 0, ar;

	while (tok_cmd[ntoken] != NULL)
	{
		ntoken++;
	}
	if (ntoken == 1)
	{
		free(tok_cmd);
		free(line);
		free(command);
		exit(status);
	}
	else if (ntoken == 2)
	{
		ar = _atoi(tok_cmd[1]);
		if (ar == -1)
		{
			_print(shellname, STDERR_FILENO);
			_print(": 1: exit: wrong num: ", STDERR_FILENO);
			_print(tok_cmd[1], STDERR_FILENO);
			_print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tok_cmd);
			free(command);
			exit(ar);
		}
	}
	else
		_print("j$: exit is just one argument\n", STDERR_FILENO);
}
