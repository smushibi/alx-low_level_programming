#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* read_from_file - Reads a specified number of
* characters from a file into a buffer.
*
* @file: Pointer to the file to read from.
* @buffer: Pointer to the buffer to store the read data.
* @letters: The number of letters it should read.
*
* Return: The actual number of letters read, or -1 if an error occurred.
*/
ssize_t read_from_file(FILE *file, char *buffer, size_t letters)
{

size_t bytesRead = fread(buffer, sizeof(char), letters, file);
if (ferror(file))
return (-1);

buffer[bytesRead] = '\0';
return (bytesRead);
}

/**
* write_to_stdout - Writes a specified amount of data to the standard output.
*
* @buffer: Pointer to the data to be written.
* @size: The number of bytes to write.
*
* Return: The actual number of bytes written, or -1 if an error occurred.
*/
ssize_t write_to_stdout(const char *buffer, size_t size)
{

ssize_t bytesWritten = write(STDOUT_FILENO, buffer, size);
return (((size_t)bytesWritten == size) ? (ssize_t)bytesWritten : -1);
}

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
*
* @filename: The name of the file to read.
* @letters: The number of letters it should read and print.
*
* Return: The actual number of letters it could read and print.
*         0 if the file cannot be opened or read, or if filename is NULL,
*         or if write fails or does not write the expected amount of bytes.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{

FILE *file;
char *buffer;

ssize_t bytesRead, bytesWritten;

if (filename == NULL)
return (0);

file = fopen(filename, "r");
if (file == NULL)
return (0);

buffer = (char *)malloc(sizeof(char) * (letters + 1));
if (buffer == NULL)
{
fclose(file);
return (0);
}

bytesRead = read_from_file(file, buffer, letters);

if (bytesRead <= 0)
{
free(buffer);
fclose(file);
return (0);
}

bytesWritten = write_to_stdout(buffer, bytesRead);

free(buffer);
fclose(file);

return (bytesWritten);
}
