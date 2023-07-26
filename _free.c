#include "shell.h"
/**
 * _free - free the memory allocated to an array
 * @array: the arry to be freed
 * Return: void
 */
void _free(char **array)
{
	int i;

	if (array == NULL)
		return;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);

}
