#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * is_palindrome - Finds whether a string is a palindrome.
 * @s: The string that will be checked.
 *
 * Return: 1 if s is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
int len = strlen(s);
int n, m;
for (n = 0, m = len - 1; n < m; n++, m--)
{
if (s[n] != s[m])
{
return (0);
}
}
return (1);
}
