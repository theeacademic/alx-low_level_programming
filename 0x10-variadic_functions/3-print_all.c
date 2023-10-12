#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_all - Prints values based on format specifiers.
 * @format: A string specifying the types of arguments.
 * @...: Variable number of arguments.
 */
void print_all(const char * const format, ...)
{
char *separator;
char *str;
int should_print;
int i;
va_list args;
va_start(args, format);
separator = "";
i = 0;
while (format && format[i])
{
should_print = 1;
switch (format[i])
{
case 'c':
printf("%s%c", separator, va_arg(args, int));
break;
case 'i':
printf("%s%d", separator, va_arg(args, int));
break;
case 'f':
printf("%s%f", separator, va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
{
printf("%s(nil)", separator);
}
else
{
printf("%s%s", separator, str);
}
break;
default:
should_print = 0;
}
if (should_print)
{
separator = ", ";
}
i++;
}
printf("\n");
va_end(args);
}
