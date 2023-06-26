#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

/**
 * display_error - Prints an error message and exits with status code 98.
 * @message: The error message to be displayed.
 */
void display_error(const char *message)
{
dprintf(2, "%s\n", message);
exit(98);
}

/**
 * read_elf_header - Reads and displays information from the ELF header.
 * @filename: The name of the ELF file.
 */
void read_elf_header(const char *filename)
{
int fd, bytes_read;
Elf32_Ehdr header;
fd = open(filename, O_RDONLY);
if (fd == -1)
display_error("Error opening file");
bytes_read = read(fd, &header, sizeof(header));
if (bytes_read != sizeof(header))
display_error("Error reading ELF header");
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
{
display_error("Not an ELF file");
}
printf("Magic: %02x %02x %02x %02x\n",
header.e_ident[EI_MAG0],
header.e_ident[EI_MAG1],
header.e_ident[EI_MAG2],
header.e_ident[EI_MAG3]);
printf("Class: %d\n", header.e_ident[EI_CLASS]);
printf("Data: %d\n", header.e_ident[EI_DATA]);
printf("Version: %d\n", header.e_ident[EI_VERSION]);
printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
printf("Type: %d\n", header.e_type);
printf("Entry point address: %x\n", header.e_entry);
close(fd);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
display_error("Usage: elf_header elf_filename");
}
read_elf_header(argv[1]);
return (0);
}

