#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: (1) on success, (-1) on failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t written_bytes = 0;
if (filename == NULL)
{
return (-1);
}
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
{
return (-1);
}
if (text_content != NULL)
{
size_t text_length = 0;
while (text_content[text_length] != '\0')
{
text_length++;
}
written_bytes = write(fd, text_content, text_length);
}
close(fd);
if (written_bytes < 0 ||
(text_content && written_bytes != (ssize_t)(strlen(text_content))))
{
return (-1);
}
return (1);
}
