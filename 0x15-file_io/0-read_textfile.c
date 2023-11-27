#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
*
* @filename: The name of the file to read.
* @letters: The number of letters to read and print.
*
* Return: The actual number of letters read and printed,
*         or 0 if the file cannot be opened or read,
*         if filename is NULL, or if write fails to write the expected amount.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor;

char *buffer;

ssize_t bytes_read, bytes_written;

if (filename == NULL)
{
fprintf(stderr, "Error: Filename is NULL.\n");
return (0);
}

file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
{
perror("Error opening the file");
return (0);
}

buffer = malloc((letters + 1) * sizeof(char));
if (buffer == NULL)
{
perror("Error allocating memory");
close(file_descriptor);
return (0);
}

bytes_read = read(file_descriptor, buffer, letters);

if (bytes_read == -1)
{
perror("Error reading from the file");
free(buffer);
close(file_descriptor);
return (0);
}

buffer[bytes_read] = '\0';

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

if (bytes_written == -1 || bytes_written != bytes_read)
{
perror("Error writing to standard output");
free(buffer);
close(file_descriptor);
return (0);
}
free(buffer);
close(file_descriptor);
return (bytes_read);
}


