#include "shell.h"
/**
 * main - code enters
 * Return: always 0
 */
int main (void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("cisfun$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
		execute_command(input);
	}
	return (0);
}
