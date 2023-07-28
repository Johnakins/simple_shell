#include "shell.h"
/**
 * tokenizer - tokenize input
 * @input: input to be parsed
 * @delimiter: delimiter to be used
 * Return: token array
 */
char **tokenizer(char *input, char *delimiter)
{
	int num_delimit = 0;
	char **av = NULL;
	char *token = NULL;
	char *ptr = NULL;

	token = _strtok_r(input, delimiter, &ptr);
	while (token != NULL)
	{
	av = _realloc(av, sizeof(*av) * num_delimit, sizeof(*av) * (num_delimit + 1));
		av[num_delimit] = token;
		token = _strtok_r(NULL, delimiter, &ptr);
		num_delimit++;
	}
	av = _realloc(av, sizeof(*av) * num_delimit, sizeof(*av) * (num_delimit + 1));
	av[num_delimit] = NULL;

	return (av);
}
/**
 * _print - prints a string
 * @string: string to be printed
 * @srm: stream to print out to
 * Return: void
 */
void _print(char *string, int srm)
{
	int i = 0;

	while (string[i] != '\0')
	{
		write(srm, &string[i], 1);
		i++;
	}
}
