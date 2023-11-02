#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);

/**
* main - Entry point of the program.
* @argc: The number of command-line arguments.
* @argv: An array of strings representing the command-line arguments.
*
* Return: 0 on success, 1 otherwise.
*/
int main(int argc, char *argv[])
{

ssize_t result;

if (argc != 2)
{
fprintf(stderr, "Usage: elf_header elf_filename\n");
exit(1);
}

result = read_textfile(argv[1], 100);
if (result == 0)
{
fprintf(stderr, "Error: Unable to read file\n");
exit(1);
}

return (0);
}
/**
* read_textfile - Reads a text file and prints it to POSIX standard output.
* @filename: The name of the file to read.
* @letters: The number of letters it should read and print.
*
* Return: The actual number of letters it could read and print.
*         If an error occurs, returns 0.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{

int fd;

char *buffer;

ssize_t bytes_read, bytes_written;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(fd);
return (0);
}

bytes_read = read(fd, buffer, letters);
close(fd);

if (bytes_read == -1)
{
free(buffer);
return (0);
}

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
free(buffer);

if (bytes_written != bytes_read)
return (0);

return (bytes_written);
}
