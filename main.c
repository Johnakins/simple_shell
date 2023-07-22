#include "shell.h"
/**
 * main - entry of the code
 * Return: always 0
 */
int main(void)
{
	char *buffer;
	char *command;
	char **args;

	while (1)
	{
		printf("#cisfun$ ");
		buffer = read_input();

		command = strtok(buffer, " ");
		args = (char **)malloc(2 * sizeof(char *));
		if (!args)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		execute_command((char *const *)args);
		free(buffer);
		free(args);
	}

	return (0);
}
