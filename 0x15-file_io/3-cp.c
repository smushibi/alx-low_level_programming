#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints an error message to stderr.
 * @message: The error message to be printed.
 */
void print_error(const char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);
}
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or an exit status on failure.
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];
if (argc != 3)
{
print_error("Usage: cp file_from file_to");
exit(97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
print_error("Can't read from file");
exit(98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
if (fd_to == -1)
{
print_error("Can't write to file");
exit(99);
}
while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
{
print_error("Can't write to file");
exit(99);
}
}
if (bytes_read == -1)
{
print_error("Can't read from file");
exit(98);
}


if (close(fd_from) == -1)
{
print_error("Can't close fd");
exit(100);
}
if (close(fd_to) == -1)
{
print_error("Can't close fd");
exit(100);
}

return 0;
}
