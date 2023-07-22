#include "shell.h"
/**
 * read_input - reads inputs on the shell
 * Return: character
 */
char *read_input()
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	printf("#cisfun$ ");

	characters_read = getline(&buffer, bufsize stdin);
	if (characters_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	buffer[strcspn(buffer "\n")] = '\0';
	return (buffer);
}