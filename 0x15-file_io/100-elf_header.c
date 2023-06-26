#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 64

/* Structure representing the ELF header */
typedef struct {
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf64_Ehdr;

/* Function to print the ELF header information */
void print_elf_header(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++) {
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS]) {
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Invalid class\n");
		break;
	}

	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA]) {
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid data encoding\n");
		break;
	}

	printf("  Version:                           %u (current)\n", header->e_version);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI]) {
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %u>\n", header->e_ident[EI_OSABI]);
		break;
	}

	printf("  ABI Version:                       %u\n", header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header->e_type) {
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("Invalid type\n");
		break;
	}

	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/* Function to read and validate the ELF header */
int read_elf_header(const char *filename, Elf64_Ehdr *header)
{
	/* Open the ELF file */
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		return -1;
	}

	/* Read the ELF header */
	ssize_t bytes_read = read(fd, header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr)) {
		fprintf(stderr, "Error reading file: %s\n", strerror(errno));
		close(fd);
		return -1;
	}

	/* Validate the ELF magic number */
	if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0) {
		fprintf(stderr, "Invalid ELF file format\n");
		close(fd);
		return -1;
	}

	close(fd);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	Elf64_Ehdr header;
	if (read_elf_header(argv[1], &header) != 0) {
		return 98;
	}

	print_elf_header(&header);

	return 0;
}
