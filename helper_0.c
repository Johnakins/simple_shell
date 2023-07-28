#include "shell.h"
/**
 * _realloc - reallocates a memory
 * @p: poiner to the memory
 * @o_size: size of p
 * @n_size: size of new memory;
 * Return: pointer to the new address memory
 */
void *_realloc(void *p, unsigned int o_size, unsigned int n_size)
{
	void *tmp;
	unsigned int i;

	if (p == NULL)
	{
		tmp = malloc(n_size);
		return (tmp);
	}
	else if (n_size == o_size)
		return (p);
	else if (n_size == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	else
	{
		tmp = malloc(n_size);
		if (tmp != NULL)
		{
			for (i = 0; i < min(o_size, n_size); i++)
				*((char *)tmp + i) = *((char *)p + i);
			free(p);
			return (tmp);
		}
		else
			return (NULL);
	}
}

/**
 * handler - handles the ctrrl-c
 * @sign: signal number
 * Return: void
 */
void handler(int sign)
{
	if (sign == SIGINT)
		_print("\n($)", STDIN_FILENO);
}
