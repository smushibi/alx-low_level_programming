#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
* error_exit - Handle error and exit with code
* @code: error code
* @msg: error message
* @file_name: name of the file (optional)
*
* Return: void
*/
void error_exit(int code, const char *msg, const char *file_name);
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: copies the content of a file to another file
 *
 * Return: 0 on success, otherwise exit code
 */
int main(int argc, char **argv)
{
int from_fd, to_fd, rbytes, wbytes;

char buffer[BUF_SIZE];

if (argc != 3)
{
error_exit(97, "Usage: cp file_from file_to\n", NULL);
}

from_fd = open(argv[1], O_RDONLY);
if (from_fd == -1)
{
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
}

to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
| S_IWUSR | S_IRGRP | S_IROTH);
if (to_fd == -1)
{
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}

while ((rbytes = read(from_fd, buffer, BUF_SIZE)) > 0)
{
wbytes = write(to_fd, buffer, rbytes);
if (wbytes == -1 || wbytes != rbytes)
{
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}
}

if (rbytes == -1)
{
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
}

if (close(from_fd) == -1)
{
error_exit(100, "Error: Can't close fd from_fd\n", NULL);
}
if (close(to_fd) == -1)
{
error_exit(100, "Error: Can't close fd to_fd\n", NULL);
}

return (0);
}

/**
* error_exit - Handle error and exit with code
* @code: error code
* @msg: error message
* @file_name: name of the file (optional)
*
* Return: void
*/
void error_exit(int code, const char *msg, const char *file_name)
{

dprintf(2, msg, file_name);
exit(code);
}
