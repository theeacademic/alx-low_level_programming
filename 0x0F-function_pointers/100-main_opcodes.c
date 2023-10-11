#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - Prints the opcodes of a function.
 * @start: Pointer to the start of the function.
 * @num_bytes: Number of bytes to print.
 */
void print_opcodes(unsigned char *start, int num_bytes) {
    int i;

    for (i = 0; i < num_bytes; i++) {
        printf("%02x", start[i]);
    }
    printf("\n");
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, 1 on incorrect argument count, 2 on negative byte count.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int num_bytes = atoi(argv[1]);

    if (num_bytes < 0) {
        printf("Error\n");
        return 2;
    }

    unsigned char *main_start = (unsigned char *)main;

    print_opcodes(main_start, num_bytes);

    return 0;
}
