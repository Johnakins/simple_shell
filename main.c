#include "shell.h"
/**
 * main - entry of the code
 * Return: always 0
 */
int main(void)
{
	char **args, *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;
	char *command;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		characters_read = getline(&buffer, &bufsize, stdin);
		if (characters_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			command = strtok(buffer, " ");
			args = (char **)malloc(2 * sizeof(char *));
			if (!args)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			args[0] = command;
			args[1] = NULL;
			execve(command, args, NULL);
			perror(command);
			free(args);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	free(buffer);
	return (0);
}
