#include "shell.h"
/**
 * path_handler - checks if command exist in PATH
 * @command: the command to look for
 * Return: pointer to the full path of the command
 */
char *path_handler(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *path_dir = strtok(path_copy, ":");
	char *full_path = (char *)malloc(strlen(path_dir) + strlen(command) + 2);

	if (path_env == NULL)
	{
		return (NULL);
	}
	if (path_copy == NULL)
	{
		perror("strdup");
		_exit(EXIT_FAILURE);
	}
	while (path_dir != NULL)
	{
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			_exit(EXIT_FAILURE);
		}
		printf(full_path, "%s%s", path_dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		path_dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
