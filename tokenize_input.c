#include "shell.h"
/**
 * tokenize_input - tokenizes the input buffer
 * @input: the user input
 * Return: array of strings
 */
char **tokenize_input(char *input)
{
	const char *delimiter = " \t\n";
	char **args = NULL;
	char *token;
	int bufsize = BUFFER_SIZE;
	int position = 0;

	args = (char **)malloc(bufsize * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, delimiter);
	while (token != NULL)
	{
		args[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			args = (char **)realloc(args, bufsize * sizeof(char *));
			if (!args)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delimiter);
	}
	args[position] = NULL;
	return (args);
}
