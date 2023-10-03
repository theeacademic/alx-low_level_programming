#include <stdlib.h>
#include "main.h"
/**
 * _strdup - Duplicate a string using malloc.
 * @str: The input string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicated string.
 *         NULL if str is NULL or if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		duplicate[i] = str[i];

	return (duplicate);
}
