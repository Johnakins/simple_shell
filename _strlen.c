#include "shell.h"
/**
 * _strlen - calculates the string length
 * @str: the string
 * Return: lenght of string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}
