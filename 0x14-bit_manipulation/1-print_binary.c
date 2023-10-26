#include <stdio.h>
#include "main.h"
/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
int i;
int flag = 0;
if (n == 0)
{
putchar('0');
return;
}
for (i = (sizeof(n) * 8) - 1; i >= 0; i--)
{
if (n & (1UL << i))
{
flag = 1;
putchar('1');
}
else if (flag)
{
putchar('0');
}
}
putchar('\n');
}
