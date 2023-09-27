#include <stdio.h>
#include "main.h"
/**
 * _pow_recursion - Finds the value of x raised to the power of y.
 * @x: The base.
 * @y: The exponent.
 *
 * Return: The result of x^y, or -1 if y is negative.
 */
int _pow_recursion(int x, int y)
{
    if (y < 0)
    {
        return (-1);
    }
    
    if (y == 0)
    {
        return (1);
    }
    
    return (x * _pow_recursion(x, y - 1));
}
