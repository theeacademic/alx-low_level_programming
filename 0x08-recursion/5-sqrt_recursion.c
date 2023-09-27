#include <stdio.h>
#include "main.h"
/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number for which the square root is to be calculated.
 * 
 * Return: The natural square root of n, or -1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
    if (n < 0)
    {
        return -1;
    }
    
    return _sqrt_recursion(n, 1);
}

/**
 * _sqrt_helper - Helper function to find the square root using recursion.
 * @n: The number for which the square root is to be calculated.
 * @guess: The current guess for the square root.
 * 
 * Return: The natural square root of n, or -1 if no natural square root is found.
 */
int _sqrt_helper(int n, int guess)
{
    if (guess * guess == n)
    {
        return guess;
    }
    else if (guess * guess > n)
    {
        return -1;
    }
    else
    {
        return _sqrt_helper(n, guess + 1);
    }
}
