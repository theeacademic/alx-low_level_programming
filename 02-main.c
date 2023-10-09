#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the name of the file it was compiled from.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    printf("Compiled from: %s\n", __FILE__);
    return (0);
}
