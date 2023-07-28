#include "shell.h"
/**
 * _strcat - concatenate two strings
 * @src: string source
 * @dest: string destination
 * Return: new address
 */
char *_strcat(char *dest, char *src)
{
	char *new = NULL;
	int l_dest = _strlen(dest);
	int l_src = _strlen(src);

	new = malloc(sizeof(*new) * (l_dest + l_src + 1));
	_strcpy(dest, new);
	_strcpy(src, new + l_dest);
	new[l_dest + l_src] = '\0';
	return (new);
}
/**
 * _strspn - get the length of a prefix substring
 * @s1: string to be searched
 * @s2: string to be used
 * Return: num of bytes in the initial segment
 */
int _strspn(const char *s1, const char *s2)
{
	int i = 0;
	int m = 0;

	while (s1[i] != '\0')
	{
		if (_strchr(s2, s1[i]) == NULL)
			break;
		m++;
		i++;
	}
	return (m);
}
/**
 * _strchr - locates a char in a string
 * @str: string to be searched
 * @c: char to be checked
 * Return: pointer to the first occurence of character in string
 */
const char *_strchr(const char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	if (str[i] == c)
		return (str + 1);
	else
		return (NULL);
}
