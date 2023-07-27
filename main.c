#include "shell.h"
/**
 * main - code enters
 * Return: always 0
 */
int main (int argc, char* argv[])
{
	char input[MAX_COMMAND_LENGTH];
	(void)argc;

	while (1)
	{
		printf("cisfun$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			fprintf(stderr, "%s: error while reading input\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
		execute_command(input, argv[0]);
	}
	return (0);
}
