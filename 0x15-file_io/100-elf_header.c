#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * display_elf_header_info - Displays information from the ELF header.
 *
 * @elf_header: The ELF header structure.
 */
void display_elf_header_info(Elf64_Ehdr elf_header)
{
printf("Magic: ");
for (int i = 0; i < EI_NIDENT; i++)
{

printf("%02x ", elf_header.e_ident[i]);
}
printf("\nClass: %s\n", elf_header.e_ident[EI_CLASS]
== ELFCLASS32 ? "ELF32" : "ELF64");
printf("Data: %s\n", elf_header.e_ident[EI_DATA]
== ELFDATA2LSB ? "2's complement, little endian"
: "2's complement, big endian");
printf("Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
printf("OS/ABI: %s\n", elf_header.e_ident[EI_OSABI]
== ELFOSABI_SYSV ? "UNIX System V" : "Other");
printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
printf("Type: %s\n", elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" :
elf_header.e_type == ET_DYN ? "DYN (Shared object file)" :
elf_header.e_type == ET_REL ? "REL (Relocatable file)" : "Other");
printf("Entry point address: %lx\n", elf_header.e_entry);
}
/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
return (98);
}

int fd = open(argv[1], O_RDONLY);

if (fd == -1)
{
perror("Error");
return (98);
}

Elf64_Ehdr elf_header;
if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
perror("Error");
close(fd);
return (98);
}

if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
elf_header.e_ident[EI_MAG3] != ELFMAG3) {
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
close(fd);
return (98);
}

lseek(fd, 0, SEEK_SET);

display_elf_header_info(elf_header);

close(fd);
return (0);
}
