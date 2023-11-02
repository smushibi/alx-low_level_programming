#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
* handle_error - Print an error message to
* stderr and exit with a specific code.
* @exit_code: The exit code.
* @message: The error message to print.
*/
void handle_error(int exit_code, const char *message)
{
dprintf(STDERR_FILENO, "%s\n", message);
exit(exit_code);
}

/**
* open_file - Opens a file with specified flags and mode.
* @filename: The name of the file to open.
* @flags: The flags to use when opening the file.
* @mode: The mode to use if creating the file.
*
* Return: The file descriptor on success.
*/
int open_file(const char *filename, int flags, mode_t mode)
{
int fd = open(filename, flags, mode);

if (fd == -1)
{
handle_error(98, "Error: Can't open file");
}
return (fd);
}

/**
* copy_data - Copies data from one file descriptor to another.
* @fd_from: The source file descriptor.
* @fd_to: The destination file descriptor.
*/
void copy_data(int fd_from, int fd_to)
{

char buffer[BUFFER_SIZE];

ssize_t bytes_read, bytes_written;

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
handle_error(99, "Error: Can't write to file");
}
}

if (bytes_read == -1)
{
handle_error(98, "Error: Can't read from file");
}
}

/**
* close_file - Closes a file descriptor.
* @fd: The file descriptor to close.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
handle_error(100, "Error: Can't close fd");
}
}

/**
* main - Copy the content of one file to another.
* @argc: The number of command-line arguments.
* @argv: An array of strings containing the arguments.
*
* Return: 0 on success, non-zero on failure.
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;

if (argc != 3)
{
handle_error(97, "Usage: cp file_from file_to");
}

fd_from = open_file(argv[1], O_RDONLY, 0);
fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

copy_data(fd_from, fd_to);

close_file(fd_from);
close_file(fd_to);

return (0);
}

