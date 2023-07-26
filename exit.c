#include "shell.h"
/**
 * builtin_exit - exits when the word exit is inputted
 * Return: 0
 */
int builtin_exit(void)
{
	exit(EXIT_SUCCESS);
}

