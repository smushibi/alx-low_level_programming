#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
* create_file - Creates a file with specified content.
*
* @filename: The name of the file to create.
* @text_content: The content to write to the file (NULL for an empty file).
*
* Return: 1 on success, -1 on failure.
*/
int create_file(const char *filename, char *text_content)
{
int file_descriptor, write_status, close_status;

if (filename == NULL)
return (-1);

file_descriptor = open(filename, O_WRONLY | O_CREAT |
O_TRUNC, S_IRUSR | S_IWUSR);
if (file_descriptor == -1)
return (-1);

if (text_content != NULL)
{
write_status = write(file_descriptor, text_content, strlen(text_content));
if (write_status == -1)
{
perror("Error writing to the file");
close(file_descriptor);
return (-1);
}
}

close_status = close(file_descriptor);
if (close_status == -1)
{
perror("Error closing the file");
return (-1);
}

return (1);
}
