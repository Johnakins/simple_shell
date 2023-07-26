#include "shell.h"
/**
 * print_environment - prints the environment of the user
 * @Return: void
 */
void print_environment()
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}
