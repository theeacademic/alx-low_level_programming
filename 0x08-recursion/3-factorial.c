#include <stdio.h>
#include "main.h"
/**
 * factorial - Factorial of a number is calculated using recursion.
 * @n: The number for which operation of factorial is done.
 * 
 * Return: The factorial of the number, or -1 if n is negative.
 */
int factorial(int n)
{
    if (n < 0)
    {
        return (-1);
    }

    if (n == 0)
    {
        return (1);
    }

    return (n * factorial(n - 1));
}
