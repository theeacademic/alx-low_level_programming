#include <stdio.h>
#include "main.h"
int find_sqrt(int n, int guess);
/**
 * _sqrt_recursion -find natural square root of a number
 * @n: number to find the square root
 *
 * Return: natural square root of n, or -1 n lacks a natural square root
 */
int _sqrt_recursion(int n)
{
if (n < 0)
{
return (-1);
}
if (n == 0 || n == 1)
{
return (n);
}
return (find_sqrt(n, 1));
}
/**
 * find_sqrt - Helper function to find the square root recursively
 * @n: The number for which to find the square root
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of n
 */
int find_sqrt(int n, int guess)
{
if (guess * guess == n)
{
return (guess);
}
if (guess > n / guess)
{
return (-1);
}
return (find_sqrt(n, guess + 1));
}
