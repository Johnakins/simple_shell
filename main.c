#include "shell.h"
/**
 * main - entry of the code
 * Return: always 0
 */
int main(void)
{
	char *buffer;
	char **args;

	while (1)
	{
		printf("#cisfun$ ");
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
