#include <stdio.h>
#include "main.h"

/**
 * _puts_recursion - uses recursion to print a string followed by a new line.
 * @s: The string that will be printed.
 */
void _puts_recursion(char *s)
{
if (*s == '\0')
{
putchar('\n');
return;
}
putchar(*s);
_puts_recursion(s + 1);
}
