#include "shell.h"
/**
 * rm_newline - removes new line from a string
 * @string: string to be used
 * Return: void
 */
void rm_newline(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '\n')
		{
			break;
		}
		i++;
	}
	string[i] = '\0';
}
/**
 * _strcpy - copies a string
 * @src: source to copy
 * @des: destination to be copied
 * Return: void
 */
void _strcpy(char *src, char *des)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
}
