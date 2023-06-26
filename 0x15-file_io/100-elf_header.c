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

/* Open the file */
fd = open(filename, O_RDONLY);
if (fd == -1)
display_error("Error opening file");
/* Read the ELF header */
bytes_read = read(fd, &header, sizeof(header));
if (bytes_read != sizeof(header))
display_error("Error reading ELF header");

/* Validate the ELF magic number */
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
{
display_error("Not an ELF file");
}

/* Display the required information */
printf("ELF Header:\n");
printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
header.e_ident[EI_MAG0],
header.e_ident[EI_MAG1],
header.e_ident[EI_MAG2],
header.e_ident[EI_MAG3],
header.e_ident[EI_CLASS],
header.e_ident[EI_DATA],
header.e_ident[EI_VERSION],
header.e_ident[EI_OSABI],
header.e_ident[EI_ABIVERSION],
header.e_type,
header.e_machine,
header.e_version,
header.e_entry,
header.e_phoff,
header.e_shoff,
header.e_flags);
printf("  Class:\t\t\t");
switch (header.e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("Invalid class\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("Unknown class\n");
break;
}
printf("  Data:\t\t\t");
switch (header.e_ident[EI_DATA])
{
case ELFDATANONE:
printf("Invalid data encoding\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;default:
printf("Unknown data encoding\n");
break;
}
printf("  Version:\t\t\t%d (current)\n", header.e_ident[EI_VERSION]);
printf("  OS/ABI:\t\t\t");
switch (header.e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_SORTIX:
printf("Sortix\n");
break;
default:
printf("Unknown OS/ABI\n");
break;
}
printf("  ABI Version:\t\t\t%d\n", header.e_ident[EI_ABIVERSION]);
printf("  Type:\t\t\t");
switch (header.e_type)
{
case ET_NONE:
printf("No file type\n");
break;
case ET_REL:
printf("Relocatable file\n");
break;
case ET_EXEC:
printf("Executable file\n");
break;
case ET_DYN:
printf("Shared object file\n");
break;
case ET_CORE:
printf("Core file\n");
break;
default:
printf("Unknown file type\n");
break;
}
printf("  Entry point address:\t\t0x%x\n", header.e_entry);
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

