#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *header);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        dprintf(2, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    Elf64_Ehdr header;
    ssize_t read_result = read(fd, &header, sizeof(header));
    if (read_result != sizeof(header) || header.e_ident[EI_MAG0] != ELFMAG0
        || header.e_ident[EI_MAG1] != ELFMAG1
        || header.e_ident[EI_MAG2] != ELFMAG2
        || header.e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(2, "Error: Not an ELF file: %s\n", argv[1]);
        exit(98);
    }

    close(fd);

    print_elf_header_info(&header);

    return 0;
}

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");

    printf("Class:   %d-bit ELF\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);

    printf("Data:    %s-endian\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");

    printf("Version: %d (current)\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI:  %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
        header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX" :
        header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD" :
        header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux" :
        header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "Solaris" : "Unknown");

    printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:    %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" :
        header->e_type == ET_DYN ? "DYN (Shared object file)" :
        header->e_type == ET_REL ? "REL (Relocatable file)" : "Unknown");

    printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

