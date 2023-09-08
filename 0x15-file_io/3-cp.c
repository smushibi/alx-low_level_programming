

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, otherwise an error code.
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buf[BUF_SIZE];
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return (97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return (98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
return (99);
}
while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
{
bytes_written = write(fd_to, buf, bytes_read);
if (bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
close(fd_to);
return (99);
}
}
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
return (98);
}
if (close(fd_from)
== -1 || close(fd_to) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd\n");
return (100);
}
return (0);
}
