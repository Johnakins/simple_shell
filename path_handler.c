#include "shell.h"
/**
 * path_handler - executes command for the shell, handles path
 * @args: array of command and its arguments
 * Return: void
 */
void path_handler(char *const args[])
{
	char *command = args[0], *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path;

	if (path == NULL)
	{
		printf("PATH environmentl variable is not set.\n");
		return;
	}
	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}
	while (token != NULL)
	{
		full_path = (char *)malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return;
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, args, NULL);
			perror(full_path);
			free(full_path);
			free(path_copy);
			return;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	printf("%s: command not found\n", command);
}
