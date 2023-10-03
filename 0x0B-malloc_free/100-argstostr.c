#include <stdlib.h>
#include "main.h"
/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: A pointer to a newly allocated concatenated string.
 *         NULL if ac == 0, av == NULL, or memory allocation fails.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k = 0;
	int total_len = 0;
	char *concatenated;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_len++;
		total_len++;
	}
	concatenated = malloc(sizeof(char) * (total_len + 1));

	if (concatenated == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			concatenated[k] = av[i][j];
			k++;
		}
		concatenated[k] = '\n';
		k++;
	}

	concatenated[k] = '\0';

	return (concatenated);
}
