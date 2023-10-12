#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - Prints strings, separated by a given separator.
 * @separator: The string to be printed between strings (can be NULL).
 * @n: The number of strings passed to the function.
 * @...: Variable number of string arguments.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
char *str;
va_start(args, n);
i = 0;
if (separator == NULL)
{
separator = "";
}
if (i < n)
{
str = va_arg(args, char *);
if (str == NULL)
{
printf("(nil)");
}
else
{
printf("%s", str);
}
i++;
while (i < n)
{
str = va_arg(args, char *);
if (str == NULL)
{
printf("%s(nil)", separator);
}
else
{
printf("%s%s", separator, str);
}
i++;
}
}
va_end(args);
printf("\n");
}
