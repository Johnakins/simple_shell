#include "shell.h"
/**
 * path_check - check PATH for command
 * @cmd: the command used
 * Return: path where the comand is found in
 */
char *path_check(char *cmd)
{
	char **path_arr = NULL;
	char *t1, *t2, *path_cpy;
	char *path = _getenv("PATH");
	int j;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path_cpy, path);
	path_arr = tokenizer(path_cpy, ":");
	for (j = 0; path_arr[j] != NULL; j++)
	{
		t2 = _strcat(path_arr[j], "/");
		t1 = _strcat(t2, cmd);
		if (access(t1, F_OK) == 0)
		{
			free(path_arr);
			free(path_cpy);
			return (t1);
		}
		free(t1);
		free(t2);
	}
	free(path_cpy);
	free(path_arr);
	return (NULL);
}
/**
 * get_func - retrieves a functin based on command
 * @cmd: string to check
 * Return: pointer to the proper function
 */
void (*get_func(char *cmd))(char **)
{
	int i;
	func_map mapping[] = {{"env", env}, {"exit", quit},};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(cmd, mapping[i].cmd_name) == 0)
			return mapping[i].func;
	}
	return (NULL);
}
