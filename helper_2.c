#include "shell.h"
/**
 * _strlen - counts string length
 * @str: the string
 * Return: length of the string
 */
int _strlen(char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
/**
 * _strcmp - compares stirngs
 * @s1: first string
 * @s2: second string
 * Return: difference for the tw string
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1 - s2);
}
/**
 * min - a helping function
 * a: variable a
 * b: varaible b
 * return: num
 */
unsigned int min(unsigned int a, unsigned int b)
{
	return (a < b ? a : b);
}
