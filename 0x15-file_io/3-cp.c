#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
* main - Entry point
*
* Return: 0 on success, 97 if incorrect number of arguments,
*         98 if can't read from file_from, 99 if can't write to file_to,
*         100 if can't close file descriptors.
*/
int main(int argc, char *argv[])
{
int file_from, file_to, rd, wr;
char buf[BUF_SIZE];

if (argc != 3)
{
dprintf(2, "Usage: cp file_from file_to\n");
exit(97);
}

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (file_to == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

while ((rd = read(file_from, buf, BUF_SIZE)) > 0)
{
wr = write(file_to, buf, rd);
if (wr != rd)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}

if (rd == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

if (close(file_from) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", file_from);
exit(100);
}
if (close(file_to) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", file_to);
exit(100);
}

return (0);
}

