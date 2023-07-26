#include "chell.h"

/*
 * pathchk - operate
 * @*str - argument vector
 *
 * returns integer
 */

int pathchk(char *str)
{
	char *cmp = "/bin/", *ptr, *j;
	int i = 0, p = 0;
       
	ptr = malloc(sizeof(char) * 50);
	if (ptr == NULL)
		return 0;

	while (cmp[i] != '\0')
	{
		if (cmp[i] != str[i])
		{
			free(ptr);
			return 0;
		}
		i++;
	}
	
	while (str[i] != '\0')
	{
		ptr[p] = str[i];
		p++;
		i++;
	}
	ptr[p] = '\0';

	j = filechk(ptr);
	if (j != NULL)
	{
		free(ptr);
		return 1;
	}
	free(ptr);
	return 0;
}

