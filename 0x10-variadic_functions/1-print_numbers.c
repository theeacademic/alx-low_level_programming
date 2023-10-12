#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_numbers - Prints numbers, separated by a given separator.
 * @separator: The string to be printed between numbers (can be NULL).
 * @n: The number of integers passed to the function.
 * @...: Variable number of integer arguments.
 */
void print_numbers(const char *separator, const unsigned int n, ...) {
va_list args;
    va_start(args, n);

    int i;

    for (i = 0; i < n; i++) {
        int num = va_arg(args, int);
        printf("%d", num);

        if (separator != NULL && i < (int)(n - 1)) {
            printf("%s", separator);
        }
    }

    va_end(args);

    printf("\n");
}
}
