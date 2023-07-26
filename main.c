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
			if (_strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(buffer);
				builtin_exit();
			}
			if (_strcmp(args[0], "env") == 0)
			{
				print_environment();
			}
			else
			{
				execute_command(args);
			}

			free(args);
		}
		free(buffer);
	}
	return (0);
}
