#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - Function to print the name using a custom printing function.
 * @name: The name to be printed.
 * @f: A pointer to a custom printing function.
 */
void print_name(char *name, void (*f)(char *))
{
f(name);
}
