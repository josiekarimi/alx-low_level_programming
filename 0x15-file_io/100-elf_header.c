#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_elf_header(const Elf64_Ehdr *header) {
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2MSB ? "big endian" : "little endian");
printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                              0x%x\n", header->e_type);
printf("  Entry point address:               0x%lx\n", header->e_entry);
printf("\n");
}
int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return (97);
}
int fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
return (98);
}
Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header)) {
fprintf(stderr, "Error: Unable to read ELF header\n");
close(fd);
return (98);
}
if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
fprintf(stderr, "Error: %s is not an ELF file\n", argv[1]);
close(fd);
return (98);
}
print_elf_header(&header);
close(fd);
return (0);
}
