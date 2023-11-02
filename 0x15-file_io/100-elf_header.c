#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>


/**
* print_error - Print an error message to stderr and exit with status code 98.
* @message: The error message to print.
*/
void print_error(const char *message)
{

dprintf(STDERR_FILENO, "%s\n", message);
exit(98);
}

/**
* read_elf_header - Reads and displays information from the ELF header.
* @filename: The name of the ELF file to read.
*/
void read_elf_header(const char *filename)
{

int fd;

Elf32_Ehdr elf_header;

fd = open(filename, O_RDONLY);
if (fd == -1)
{
print_error("Error: Unable to open file");
}

if (read(fd, &elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
{
print_error("Error: Unable to read ELF header");
}

close(fd);


printf("Magic: ");
for (int i = 0; i < EI_NIDENT; i++)
{

printf("%02x ", elf_header.e_ident[i]);
}
printf("\n");

printf("Class: %s\n",
(elf_header.e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
printf("Data: %s\n", (elf_header.e_ident[EI_DATA] == ELFDATA2LSB)
? "2's complement, little endian" : "2's complement, big endian");

printf("Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
printf("OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
printf("Type: %d\n", elf_header.e_type);
printf("Entry point address: %#lx\n", (unsigned long)elf_header.e_entry);

}

/**
* main - Entry point of the program.
* @argc: The number of command-line arguments.
* @argv: An array of strings containing the arguments.
* Return: 0 on success, non-zero on failure.
*/
int main(int argc, char *argv[])
{

if (argc != 2)
{
print_error("Usage: elf_header elf_filename");
}

read_elf_header(argv[1]);

return (0);
}
