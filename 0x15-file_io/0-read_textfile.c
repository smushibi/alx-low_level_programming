#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* read_textfile - Reads a text file and prints
* it to the POSIX standard output.
* @filename: The name of the file to read.
* @letters: The number of letters it should read and print.
* Return: The actual number of letters it could read and print.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *file;
char *buffer;

size_t read_count;
ssize_t written_count;
if (filename == NULL)
return (0);
file = fopen(filename, "r");
if (file == NULL)
return (0);
buffer = (char *)malloc(letters + 1);
if (buffer == NULL)
{
fclose(file);
return (0);
}
read_count = fread(buffer, sizeof(char), letters, file);
if (ferror(file) != 0)
{
free(buffer);
fclose(file);
return (0);
}
buffer[read_count] = '\0';
written_count = write(STDOUT_FILENO, buffer, read_count);
if (written_count != read_count)
{
free(buffer);
fclose(file);
return (0);
}
free(buffer);
fclose(file);
return (read_count);
}
