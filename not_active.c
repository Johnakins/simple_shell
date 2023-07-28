#include "shell.h"
/**
 * not_active - handles not interactive mode
 * Return: void
 */
void not_active(void)
{
	char **current_command = NULL;
	int typ_command = 0;
	size_t line_size = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &line_size, stdin) != -1)
		{
			rm_newline(line);
			rm_comment(line);
			command = tokenizer(line, ";");
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
	exit(status);
}
