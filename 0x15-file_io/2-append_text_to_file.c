#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The text content to add to the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int file_descriptor;
    ssize_t content_length = 0;

    if (filename == NULL)
        return (-1);

    if (text_content == NULL)
        return (1);

    file_descriptor = open(filename, O_WRONLY | O_APPEND);

    if (file_descriptor == -1)
        return (-1);

    while (text_content[content_length] != '\0')
        content_length++;

    if (write(file_descriptor, text_content, content_length) == -1)
    {
        close(file_descriptor);
        return (-1);
    }

    close(file_descriptor);
    return (1);
}
