#include "shell.h"
/**
 * run_shell - runs shell
 * Return: void
 */
void run_shell(void)
{
	char *line;
	size_t bufsize = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;
	char **args = malloc(2 *sizeof(char *));
	char *const envp[] = {NULL};

	while (1)
	{
		printf("($) ");
		nread = getline(&line, &bufsize, stdin);

		if (nread == EOF)
		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
		}
		else if (child_pid == 0)
		{
			if (nread > 1)
			{
				if (!args)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}
				args[0] = line;
				args[1] = NULL;
				if (execve(line, args, envp) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				printf("Command not found\n");
				exit(EXIT_FAILURE);
			}
		}
			else
			{
				wait(&status);
			}
		}
	free(line);
}
