#include "shell.h"
/**
 * locate_cmd - locates the command in the PATH
 * @command: the command to be found
 * Return: character
 */
char *locate_cmd(char *command)
{
	struct stat buffer;
	char *place;
	char *place_copy;
	char *place_token;
	char *file_place;
	int cmdlen;
	int dirlen;

	place = getenv("PATH");

	if (place)
	{
		place_copy = strdup(place);
		cmdlen = strlen(command);
		place_token = strtok(place_copy, ":");

		while (place_token != NULL)
		{
			dirlen = strlen(place_token);
			file_place = malloc(cmdlen + dirlen + 2);

			strcpy(file_place, place_token);
			strcat(file_place, "/");
			strcat(file_place, command);
			strcat(file_place, "\0");

			if (stat(file_place, &buffer) == 0)
			{
				free(place_copy);
				return (file_place);
			}
			else
			{
				free(file_place);
				place_token = strtok(NULL, ":");
			}

		}

		free(place_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
