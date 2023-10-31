#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "main.h"
/**
 * main - Copy the content of one file to another file
 * @argc: The number of command line arguments
 * @argv: An array of command line arguments
 * Return: 0 on success, otherwise error code
 */
int main(int argc, char *argv[])
{
int src_fd, dest_fd;
char buffer[1024];
ssize_t bytes_read;
if (argc != 3)
{
dprintf(2, "Usage: cp file_from file_to\n");
exit(97);
}
src_fd = open(argv[1], O_RDONLY);
if (src_fd == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
dest_fd = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (dest_fd == -1)
{
dprintf(2, "Error: Can't write to file %s\n", argv[2]);
exit(99);
}
while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0)
{
if (write(dest_fd, buffer, bytes_read) == -1)
{
dprintf(2, "Error: Can't write to file %s\n", argv[2]);
exit(99)
}
}
if (bytes_read == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
if (close(src_fd) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", src_fd);
exit(100);
}
if (close(dest_fd) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", dest_fd);
exit(100);
}
return (0);
}
