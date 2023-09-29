#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int sum = 0;
int i;
if (argc == 1)
{
printf("0\n");
return (0);
}
for (i = 1; i < argc; i++)
{
char *endptr;
long num = strtol(argv[i], &endptr, 10);
if (*endptr != '\0' || num < 0)
{
printf("Error\n");
return (1);
}
sum += (int)num;
}
printf("%d\n", sum);
return (0);
}
