#include "shell.h"
/**
 * env_builtin - prints the current environment
 * Return: void
 */
void env_builtin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
