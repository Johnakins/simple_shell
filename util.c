#include "shell.h"
/**
 * parse_cmd - determines the type of the command
 * @cmd: command to be parsed
 * Return: represent the type of the command all the time
 */
int parse_cmd(char *cmd)
{
	int i;
	char *inner_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (OUTTER_CMD);
	}
	for (i = 0; inner_cmd[i] != NULL; i++)
	{
		if (_strcmp(cmd, inner_cmd[i]) == 0)
			return (INNER_CMD);
	}
	path = path_check(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}
	return (INV_CMD);
}
/**
 * _getenv - gets value of an environment
 * @n: name of the env
 * Return: the value of the varable
 */
char *_getenv(char *n)
{
	char **environment;
	char *ptr;
	char *cpy_name;

	for (environment = environ; *environment != NULL; environment++)
	{
		for (ptr = *environment, cpy_name = n; *ptr == *cpy_name; ptr++, cpy_name++)
		{
			if (*ptr == '=')
				break;
		}
		if ((*ptr == '=') && (*cpy_name == '\0'))
			return (ptr + 1);
	}
	return (NULL);
}
