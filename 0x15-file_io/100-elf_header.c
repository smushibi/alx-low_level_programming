#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
* print_elf_header_info - Displays the information contained in the ELF header
* @hdr: Pointer to Elf64_Ehdr header structure
*/
void print_elf_header_info(Elf64_Ehdr *hdr);

/**
* main - Entry point
* @argc: argument count
* @argv: argument vector
* Return: 0 on success, 98 on failure
*/
int main(int argc, char *argv[])
{

int fd;

Elf64_Ehdr elf_hdr;

if (argc != 2)
{
dprintf(2, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(2, "Error: Could not open file\n");
exit(98);
}

if (read(fd, &elf_hdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
dprintf(2, "Error: Could not read ELF header\n");
exit(98);
}

if (elf_hdr.e_ident[EI_MAG0] != ELFMAG0
|| elf_hdr.e_ident[EI_MAG1] != ELFMAG1 ||
elf_hdr.e_ident[EI_MAG2] != ELFMAG2 || elf_hdr.e_ident[EI_MAG3] != ELFMAG3) {
dprintf(2, "Error: Not an ELF file\n");
exit(98);
}

print_elf_header_info(&elf_hdr);
close(fd);
return (0);
}

/**
* print_elf_header_info - Displays the information contained in the ELF header
* @hdr: Pointer to Elf64_Ehdr header structure
*/
void print_elf_header_info(Elf64_Ehdr *hdr)
{
int i;

printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", hdr->e_ident[i]);
}
printf("\n");

printf("  Class:                             %s\n", (hdr->e_ident[EI_CLASS]
== ELFCLASS64) ? "ELF64" : "ELF32");
printf("  Data:                              %s\n", (hdr->e_ident[EI_DATA]
== ELFDATA2LSB) ? "2's complement, little endian" :
"2's complement, big endian");
printf("  Version:                           %d (current)\n",
hdr->e_ident[EI_VERSION]);
printf("  OS/ABI:                            %d\n",
hdr->e_ident[EI_OSABI]);
printf("  ABI Version:%d\n", hdr->e_ident[EI_ABIVERSION]);
printf("  Type:                              %d\n", hdr->e_type);
printf("  Entry point address:               0x%lx\n", hdr->e_entry);
}
