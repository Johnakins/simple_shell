#include "shell.h"
/**
 * main - entry of the code
 * Return: always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		printf("#cisfun$ ");
		command = read_input();
		if (command == NULL)
		{
			printf("\n");
			break;
		}

		if (*command)
			execute_command(command);

		free(command);
	}

	return (0);
}
