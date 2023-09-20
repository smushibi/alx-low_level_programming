 * display_elf_header - Displays information contained in the ELF header
 * @filename: Path of the ELF file
 * Description:
 * This function opens the specified ELF file, reads its header, and displays
 * relevant information including magic number, class, data format, version,
 * OS/ABI, ABI version, type, and entry point address.
 *
 * If there is an error in opening, reading, or if the file is not a valid ELF
 * file, it prints an error message and exits with status code 98.
 *
 * Format: the same as readelf -h (version 2.26.1)
 * If the file is not an ELF file, or on error, exit with status code 98 and
 * display a comprehensive error message to stderr.
 *
 * You are allowed to use lseek once.
 * You are allowed to use read a maximum of 2 times at runtime.
 * You are allowed to have as many functions as you want in your source file.
 * You are allowed to use printf.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

void display_elf_header(char *filename)
{
int fd;

Elf32_Ehdr header;
int i;

fd = open(filename, O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error opening file '%s'\n", filename);
exit(98);
}
if (read(fd, &header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
{
fprintf(stderr, "Error reading ELF header\n");
close(fd);
exit(98);
}
if (memcmp(header.e_ident, "\177ELF", 4) != 0)
{
fprintf(stderr, "Not an ELF file: '%s'\n", filename);
close(fd);
exit(98);
}
printf("Magic:   ");
for (i = 0; i < 16; i++)
{
printf("%02x ", header.e_ident[i]);
}
printf("\n");
printf("Class:   %s\n", (header.e_ident[4] == 1) ? "ELF32" : "ELF64");
printf("Data:    %s\n", (header.e_ident[5] == 1) ?
	"2's complement, little endian" : "2's complement, big endian");
printf("Version: %u\n", header.e_version);
printf("OS/ABI:  %u\n", header.e_ident[7]);
printf("ABI Version: %u\n", header.e_ident[8]);
printf("Type:    %u\n", header.e_type);
printf("Entry point address: 0x%lx\n", (unsigned long)header.e_entry);
close(fd);
}
/**
 * main - Entry point program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Description:
 * This program takes the path of an ELF file as a command-line argument
 * and displays information about its ELF header.
 *
 * If there are any errors in opening, reading,
 * or if the file is not a valid ELF
 * file, it prints an error message to stderr and exits with status code 1.
 *
 * If the file is a valid ELF file, it displays relevant information including
 * magic number, class, data format, version, OS/ABI, ABI version, type, and
 * entry point address.
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
char *filename;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (1);
}
filename = argv[1];
display_elf_header(filename);
return (0);
}
