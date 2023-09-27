#include <stdio.h>

/**
 * _strlen_recursion - uses recursion to return the length of a string.
 * @s: The string for which length must be determined
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
    if (*s == '\0')
    {
        return (0);
    }

    return (1 + _strlen_recursion(s + 1));
}
