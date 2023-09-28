#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * is_palindrome_recursive - Finds whether a string a palindrome by recursion.
 * @s: The string that will be checked.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if s is a palindrome, 0 otherwise.
 */
int is_palindrome_recursive(char *s, int start, int end)
{
if (start >= end)
{
return (1);
}
if (s[start] != s[end])
{
return (0);
}
return (is_palindrome_recursive(s, start + 1, end - 1));
}
/**
 * is_palindrome - Finds whether  a string is a palindrome.
 * @s: The string that will be checked.
 *
 * Return: 1 if s is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
int len = strlen(s);
return (is_palindrome_recursive(s, 0, len - 1));
}
