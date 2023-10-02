#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
* error_exit - Prints an error message and exits the program with a specified code.
*
* @code: The exit code.
* @message: The error message to print.
*/
void error_exit(int code, const char *message)
{
dprintf(STDERR_FILENO, "Error: %s\n", message);
exit(code);
}

int main(int argc, char *argv[])
{
int fd_from, fd_to;
const char *file_from, *file_to;
char buffer[BUFFER_SIZE];
ssize_t bytes_read, bytes_written;

if (argc != 3)
{
error_exit(97, "Usage: cp file_from file_to");
}

file_from = argv[1];
file_to = argv[2];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
{
error_exit(98, "Can't read from file");
}

fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
close(fd_from);
error_exit(99, "Can't write to file");
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
{
close(fd_from);
close(fd_to);
error_exit(99, "Can't write to file");
}
}

if (bytes_read == -1)
{
close(fd_from);
close(fd_to);
error_exit(98, "Can't read from file");
}

if (close(fd_from) == -1 || close(fd_to) == -1)
{
error_exit(100, "Can't close file descriptor");
}

return 0;
}
