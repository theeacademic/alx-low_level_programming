#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 *         The last element is NULL.
 *         NULL if str == NULL, str == "" or memory allocation fails.
 */
char **strtow(char *str)
{
	char **words;
	int i, j, word_count = 0, word_len = 0;
	int in_word = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	int i;


	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			word_count++;
			in_word = 1;
		}
		else if (str[i] == ' ')
		{
			in_word = 0;
		}
	}

	words = malloc(sizeof(char *) * (word_count + 1));

	if (words == NULL)
		return (NULL);

	in_word = 0;
	word_len = 0;
	j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			in_word = 1;
			word_len = 1;
		}
		else if (str[i] == ' ')
		{
			if (in_word)
			{
				words[j] = malloc(sizeof(char) * (word_len + 1));
				if (words[j] == NULL)
				{
					for (i = 0; i < j; i++)
						free(words[i]);
					free(words);
					return (NULL);
				}
				in_word = 0;
				word_len = 0;
				j++;
			}
		}
		else
		{
			word_len++;
		}
	}

	if (in_word)
	{
		words[j] = malloc(sizeof(char) * (word_len + 1));
		if (words[j] == NULL)
		{
			for (i = 0; i < j; i++)
				free(words[i]);
			free(words);
			return (NULL);
		}
	}

	in_word = 0;
	word_len = 0;
	j = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			in_word = 1;
			word_len = 1;
			words[j][0] = str[i];
		}
		else if (str[i] == ' ')
		{
			if (in_word)
			{
				words[j][word_len] = '\0';
				in_word = 0;
				word_len = 0;
				j++;
			}
		}
		else
		{
			words[j][word_len] = str[i];
			word_len++;
		}
	}

	if (in_word)
	{
		words[j][word_len] = '\0';
		j++;
	}

	words[j] = NULL;

	return (words);
}

int main(void)
{
    char **words;
    char *str = "Hello World";

    words = strtow(str);

    if (words == NULL)
    {
        printf("Failed to split the string.\n");
        return (1);
    }

    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    free(words);

    return (0);
}
