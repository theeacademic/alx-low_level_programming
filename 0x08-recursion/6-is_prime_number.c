#include <stdio.h>
#include <math.h>

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
    int i;

    if (n <= 1)
    {
        return 0;
    }

    if (n <= 3)
    {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }

    for (i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0;
        }
    }

    return 1;
}
