/*
* File: copy.c
* Author: ChatGPT
* Description: This program copies the content of a file to another file.
*              Usage: ./copy file_from file_to
*              Exit Codes:
*                - 97: Incorrect number of arguments
*                - 98: Can't read from file_from or file does not exist
*                - 99: Can't write to file_to or write failure
*                - 100: Can't close file descriptor
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
* error_exit - Prints an error message and
* exits the program with a specified code.
* @code: The exit code.
* @message: The error message format.
* @arg: The argument for the error message.
*/
void error_exit(int code, const char *message, int arg)
{
dprintf(STDERR_FILENO, message, arg);
exit(code);
}

/**
* openFile - Opens a file with the specified flags and mode.
* @filename: The name of the file to open.
* @flags: The flags for opening the file.
* @mode: The mode to set for the file (for O_CREAT).
* Return: The file descriptor.
*/
int openFile(const char *filename, int flags, mode_t mode)
{

int fd = open(filename, flags, mode);

if (fd == -1)
{
error_exit(99, "Error: Can't open file %s\n", 0);
}
return (fd);
}

/**
* copyData - Copies data from one file descriptor to another.
* @fd_from: The source file descriptor.
* @fd_to: The destination file descriptor.
*/
void copyData(int fd_from, int fd_to)
{

char buffer[BUFFER_SIZE];

ssize_t bytes_read, bytes_written;

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written != bytes_read)
{
error_exit(99, "Error: Can't write to file\n", 0);
}
}

if (bytes_read == -1)
{
error_exit(98, "Error: Can't read from file\n", 0);
}
}

/**
* main - Entry point of the program.
* @argc: Number of command-line arguments.
* @argv: Array of command-line argument strings.
* Return: 0 on success, other values on failure.
*/
int main(int argc, char *argv[])
{

const char *file_from;

const char *file_to;

int fd_from, fd_to;

if (argc != 3)
{
error_exit(97, "Usage: ./copy file_from file_to\n", 0);
}

file_from = argv[1];
file_to = argv[2];

fd_from = openFile(file_from, O_RDONLY, 0);
fd_to = openFile(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

copyData(fd_from, fd_to);

if (close(fd_from) == -1)
{
error_exit(100, "Error: Can't close fd %d\n", fd_from);
}

if (close(fd_to) == -1)
{
error_exit(100, "Error: Can't close fd %d\n", fd_to);
}

return (0);
}

