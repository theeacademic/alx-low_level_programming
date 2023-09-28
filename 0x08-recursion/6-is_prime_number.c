#include <stdio.h>
#include "main.h"
int is_prime_recursive(int n, int divisor);
/**
 * is_prime_number - Wrapper function to checks if a number is prime
 * @n: The number to check for primality
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
return ((is_prime_recursive(n, n - 1)));
}
/**
 * is_prime_recursive - Helper function finds if a number is prime recursively
 * @n: The number that check for primality
 * @divisor: The current divisor being checked
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_recursive(int n, int divisor)
{
if (n < 2)
{
return (0);
}
if (divisor == 1)
{
return (1);
}
if (n % divisor == 0)
{
return (0);
}
return ((is_prime_recursive(n, divisor - 1)));
}
