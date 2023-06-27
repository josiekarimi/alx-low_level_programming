#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#define ELF_MAGIC_SIZE 4

struct ElfHeader {
	unsigned char e_ident[ELF_MAGIC_SIZE]; /* ELF identification bytes */
	uint8_t e_class;                       /* ELF class (32-bit or 64-bit) */
	uint8_t e_data;                        /* ELF data encoding (little-endian or big-endian) */
	uint8_t e_version;                     /* ELF version */
	uint8_t e_osabi;                       /* OS-specific ELF ABI */
	uint8_t e_abiversion;                  /* ELF ABI version */
	uint16_t e_type;                       /* ELF file type */
	uint32_t e_entry;                      /* Entry point address */
};

/**
 * print_elf_header - Prints the ELF header information
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(const struct ElfHeader *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < ELF_MAGIC_SIZE; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ELF%d\n", header->e_class == 1 ? 32 : 64);
	printf("  Data:                              %s\n", header->e_data == 1 ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_version);
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       %d\n", header->e_abiversion);
	printf("  Type:                              %s (Shared object file)\n", header->e_type == 2 ? "EXEC" : "DYN");
	printf("  Entry point address:               %#x\n", header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (1);
	}

	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		return (98);
	}

	struct ElfHeader header;
	ssize_t bytes_read = read(fd, &header, sizeof(struct ElfHeader));
	if (bytes_read != sizeof(struct ElfHeader))
	{
		fprintf(stderr, "Error reading ELF header from file: %s\n", filename);
		close(fd);
		return (98);
	}

	print_elf_header(&header);
	close(fd);
	return (0);
}
