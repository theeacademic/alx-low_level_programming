#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
if (argc >= 1)
{
printf("%s\n", argv[0]);
return (0);
}
else
{
fprintf(stderr, "Unable to retrieve program name\n");
return (1);
}
}
