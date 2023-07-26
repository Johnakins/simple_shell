#include "shell.h"
/**
 * main - code enters
 * Return: always 0
 */
int main(void)
{
	char *buffer;
	char **args;

	while (1)
	{
		printf("simple_shell$ ");
		buffer = read_input();

		args = tokenize_input(buffer);
		if (args != NULL)
		{
			execute_command(args);
			free(args);
		}
		free(buffer);
	}
	return (0);
}
