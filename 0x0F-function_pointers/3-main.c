#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 for success, 98 for wrong number of arguments, 99 for invalid operator, 100 for division/modulo by zero
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;
    char *operator;
    int (*operation)(int, int);

    if (argc != 4)
    {
        printf("Error\n");
        exit(98);
    }

    num1 = atoi(argv[1]);
    operator = argv[2];
    num2 = atoi(argv[3]);

    operation = get_op_func(operator);

    if (operation == NULL)
    {
        printf("Error\n");
        exit(99);
    }

    if ((*operator == '/' || *operator == '%') && num2 == 0)
    {
        printf("Error\n");
        exit(100);
    }

    result = operation(num1, num2);
    printf("%d\n", result);

    return (0);
}
