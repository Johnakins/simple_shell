#include "shell.h"
/**
 * main - entry of the code
 * @ac: argument count
 * @argv: argument vector
 * Return: always 0
 */
int main(int ac, char **av)
{
	char *prompt = "jash@$> ";
	char *line = NULL;
	char *line_copy = NULL;
	size_t i = 0;
	ssize_t readc;
	const char *delim = " \n";
	int tokens_num = 0;
	char *token;

	(void)ac;

	while (1)
	{
	printf("%s", prompt);
	readc = getline(&line, &i, stdin);

	if (readc == -1)
	{
		printf("Exiting jash ....\n");
		return (-1);
	}

	line_copy = malloc(sizeof(char) * readc);
	if (line_copy == NULL)
	{
		perror("Oops: memory allocation error");
		return (-1);
	}
	strcpy(line_copy, line);

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens_num++;
		token = strtok(NULL, delim);
	}
	tokens_num++;

	av = malloc(sizeof(char *) * tokens_num);
	token = strtok(line_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(char) * strlen(token));
		strcpy(av[i], token);

		token = strtok(NULL, delim);
	}

	av[i] = NULL;

	if (strcmp(av[0], "exit") == 0)
	{
		exit_shell();
		break;
	}

	execute_cmd(av);
	}

	free(line);
	free(line_copy);
	return (0);
}
