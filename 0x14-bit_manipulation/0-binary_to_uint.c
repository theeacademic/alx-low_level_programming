#include <stddef.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: Pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there are invalid characters or b is NULL.
 */
unsigned int binary_to_uint(const char *b) {
    unsigned int result = 0;
    int i = 0;

    if (b == NULL)
        return 0;

    while (b[i] != '\0') {
        char c = b[i];

        if (c == '0') {
            result <<= 1;
        } else if (c == '1') {
            result = (result << 1) | 1;
        } else {
            return 0;
        }
        i++;
    }

    return result;
}
