#include "shell.h"
/**
 * tokenize_input - tokenizes the input buffer into an array of strings
 * @input: input buffer containing the command and arguments
 * Return: array of strings
 */
char **tokenize_input(char *input)
{
	const char *delimiters = " \t\n";
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

	token = strtok(input, delimiters);
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
		token = strtok(NULL, delimiters);
	}
	args[position] = NULL;
	return (args);
}
