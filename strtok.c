#include "shell.h"
/**
 * _strtok_r - tokenizes a string
 * @str: string to be tokenized
 * @d: delimiter
 * @ptr: pointer
 * Return: the next avail token
 */
char *_strtok_r(char *str, const char *delim, char **ptr)
{
	char *final;

	if (str == NULL)
		str = *ptr;
	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}
	str += _strspn(str, delim);
	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}
	final = str + _strcspn(str, delim);
	if (*final == '\0')
	{
		*ptr = (*final != '\0') ? final + 1 : final;
		return (str);
	}
	*final = '\0';
	*ptr = final + 1;
	return (str);
}
/**
 * _strcspn - computes segment of str 1
 * @s1: string to be search
 * @s2: string to be used
 * Return: index
 */
int _strcspn(const char *s1, const char *s2)
{
	int l = 0, i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (_strchr(s2, s1[i]) != NULL)
			break;
		l++;
	}
	return (l);
}
