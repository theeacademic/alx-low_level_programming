#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * create_file - Creates a file with specified permissions and writes text content to it
 * @filename: The name of the file to create or open
 * @text_content: The text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int file_descriptor;
    ssize_t content_length = 0;

    if (filename == NULL)
        return (-1);

    file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (file_descriptor == -1)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[content_length] != '\0')
            content_length++;

        if (write(file_descriptor, text_content, content_length) == -1)
        {
            close(file_descriptor);
            return (-1);
        }
    }

    close(file_descriptor);
    return (1);
}
