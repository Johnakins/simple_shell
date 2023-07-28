#include "shell.h"
/**
 * rm_comment - ignore everything after a '#'
 * @input: input to be used
 * Return: void
 */
void rm_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input = '\0';
}
/**
 * _atoi - changes a string to num
 * @str: string to be changed
 * Return: int (converted)
 */
int _atoi(char *str)
{
	unsigned int i = 0;

	do
	{
		if (*str == '-')
			return (-1);
		else if ((*str < '0' || *str > '9') && *str != '\0')
			return (-1);
		else if (*str >= '0' && *str <= '9')
			i = (i * 10) + (*str - '0');
		else if (i > 0)
			break;
	} while (*str++);
	return (i);
}
