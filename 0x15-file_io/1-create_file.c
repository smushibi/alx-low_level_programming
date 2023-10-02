#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
/**
* create_file - Creates a file with specified content.
*
* @filename: The name of the file to create.
* @text_content: The content to write to the file (NULL-terminated string).
*
* Return: 1 on success, -1 on failure.
*         If filename is NULL or if the file cannot
*           be created/written, return -1.
*         If text_content is NULL, create an empty file.
*/
int create_file(const char *filename, char *text_content)

{
int fd;

if (filename == NULL)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
ssize_t bytes_written = write(fd, text_content, strlen(text_content));
if (bytes_written == -1)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
