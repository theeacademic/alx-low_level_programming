#include <stdio.h>
#include "main.h"
/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
    int numBits = sizeof(n) * 8;
    int i;

    for (i = numBits - 1; i >= 0; i--)
    {
        unsigned long int mask = 1UL << i;
        putchar((n & mask) ? '1' : '0');
    }

    putchar('\n');
}
