#include "shell.h"
/**
 * _split - splits a string into an array of string
 * @str: input string
 * @delimiter: the character to use for splitting
 * @num_tokens: pointer to store the number
 * Return: an array of strings
 */
char **split_string(const char *str, char delimiter, int *num_tokens)
{
	const char *c = str;
	char **result = (char **)malloc((*num_tokens + 1) * sizeof(char *));
	int token_count = 0;
	const char *start = str;
	size_t token_len;

	if (str == NULL || num_tokens == NULL)
		return (NULL);

	*num_tokens = 1;
	while(*c)
	{
		if (*c == delimiter)
		{
			(*num_tokens)++;
		}
		c++;
	}

	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (*c)
	{
		if (*c == delimiter || *(c + 1) == '\0')
		{
			token_len = (size_t)(c - start) + (*(c + 1) == '\0' ? 1 : 0);
			result[token_count] = (char *)malloc((token_len + 1) * sizeof(char));
			if (!result[token_count])
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strncpy(result[token_count], start, token_len);
			result[token_count][token_len] = '\0';
			token_count++;
			start = c + 1;
		}
		c++;
	}
	result[token_count] = NULL;
	return (result);
}
