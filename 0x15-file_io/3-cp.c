#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * open_source_file - Opens the source file and handles errors.
 * @filename: The name of the source file.
 * Return: File descriptor of the opened source file.
 */
int open_source_file(const char *filename);
/**
 * open_destination_file - Opens the destination file and handles errors.
 * @filename: The name of the destination file.
 * Return: File descriptor of the opened destination file.
 */
int open_destination_file(const char *filename);
/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd);
#define BUFFER_SIZE 1024
int main(int argc, char *argv[])
{int src_fd, dest_fd;
char buffer[BUFFER_SIZE];
ssize_t bytes_read;
if (argc != 3)
{dprintf(2, "Usage: cp file_from file_to\n");
exit(97);}
src_fd = open_source_file(argv[1]);
dest_fd = open_destination_file(argv[2]);
while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
{if (write(dest_fd, buffer, bytes_read) == -1)
{dprintf(2, "Error: Can't write to file %s\n", argv[2]);
exit(99);
}
}
if (bytes_read == -1)
{dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
close_file(src_fd);
close_file(dest_fd);
return (0);
}
int open_source_file(const char *filename)
{int src_fd = open(filename, O_RDONLY);
if (src_fd == -1)
{dprintf(2, "Error: Can't read from file %s\n", filename);
exit(98);
}
return src_fd;
}
int open_destination_file(const char *filename)
{int dest_fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (dest_fd == -1)
{dprintf(2, "Error: Can't write to file %s\n", filename);
exit(99);
}
return dest_fd;
}
void close_file(int fd)
{if (close(fd) == -1)
{dprintf(2, "Error: Can't close fd %d\n", fd);
exit(100);
}
}
