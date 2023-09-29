#include <stdio.h>
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
(void)argc;
if (argc > 1)
{
printf("%d\n", argc - 1);
}
else
{
printf("0\n");
}
(void)argv[0];
return (0);
}
