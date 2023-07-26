#include "shell.h"
/**
 * _getenv - gets the environment variable
 * @var: variable to be found
 * Return: a pointer
 */
char **_getenv(char *var)
{
	char **values = NULL;
	int count = 0;
	int i;
	char *value;
       
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, strlen(var)) == 0 && environ[i][strlen(var)] == '=')
		{
			value = environ[i] + _strlen(var) + 1;
			values = split_string(value, ',', &count);
			break;
		}
	}
	return (values);

}
