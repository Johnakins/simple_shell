#include "shell.h"
char **command = NULL;
char *shellname = NULL;
char *line = NULL;
int status = 0;
/**
 * main - code enters
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char **current_command = NULL;
	int typ_command = 0;
	size_t line_size = 0;
	char *line = NULL;
	char **command = NULL;
	char *shellname;
	int status = 0;
	int i;
	(void)argc;

	signal(SIGINT, handler);
	shellname = argv[0];
	while (1)
	{
		printf("j$ ");

		if (getline(&line, &line_size, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		rm_newline(line);
		rm_comment(line);
		command = tokenizer(line, ";");
		for (i = 0; command[i] != NULL; i++)
		{
			current_command = tokenizer(command[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			typ_command = parse_cmd(current_command[0]);
			ini_tializer(current_command, typ_command, shellname);
			free(current_command);
		}
		free(command);
	}
	free(line);
	return (status);
}
