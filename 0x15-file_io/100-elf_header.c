#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
* display_error - Displays an error message and exits
* @message: The error message to display
*
* Description:
* This function prints an error message to stderr and exits the program with
* status code 98.
*/
void display_error(char *message)
{
fprintf(stderr, "Error: %s\n", message);
exit(98);
}
/**
* display_magic_number - Displays the magic number of the ELF header
* @ident: The array containing the magic number
*
* Description:
* This function prints the magic number in hexadecimal format.
*/
void display_magic_number(unsigned char *ident)
{
printf("Magic:   ");
for (int i = 0; i < 16; i++)
{
printf("%02x ", ident[i]);
}
printf("\n");
}
/**
* display_elf_header_info - Displays information from the ELF header
* @header: Pointer to the ELF header structure
*
* Description:
* This function prints information like class, data format, version, etc.
* from the ELF header.
*/
void display_elf_header_info(Elf32_Ehdr *header)
{
printf("Class:   %s\n", (header->e_ident[4] == 1) ? "ELF32" : "ELF64");
printf("Data:    %s\n", (header->e_ident[5] == 1) ?
	"2's complement, little endian" : "2's complement, big endian");
printf("Version: %u\n", header->e_version);
printf("OS/ABI:  %u\n", header->e_ident[7]);
printf("ABI Version: %u\n", header->e_ident[8]);
printf("Type:    %u\n", header->e_type);
printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}
/**
* read_elf_header - Reads and validates the ELF header from a file
* @filename: Path of the ELF file
* @header: Pointer to the ELF header structure
*
* Description:
* This function opens the specified ELF file, reads its header, and performs
* necessary validations. If any errors occur, it displays an error message and
* exits with status code 98.
*/
void read_elf_header(char *filename, Elf32_Ehdr *header)
{
int fd = open(filename, O_RDONLY);
if (fd == -1)
{
display_error("Failed to open file");
}
if (read(fd, header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
{
close(fd);
display_error("Failed to read ELF header");
}
if (memcmp(header->e_ident, "\177ELF", 4) != 0)
{
close(fd);
display_error("Not an ELF file");
}
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
if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (1);
}
char *filename = argv[1];
Elf32_Ehdr header;
read_elf_header(filename, &header);
display_magic_number(header.e_ident);
display_elf_header_info(&header);
return (0);
}
