#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

const char *get_elf_class(unsigned char elf_class) {
    switch (elf_class) {
        case ELFCLASS32:
            return "ELF32";
        case ELFCLASS64:
            return "ELF64";
        default:
            return "Unknown";
    }
}

const char *get_elf_data(unsigned char elf_data) {
    switch (elf_data) {
        case ELFDATA2LSB:
            return "2's complement, little endian";
        case ELFDATA2MSB:
            return "2's complement, big endian";
        default:
            return "Unknown";
    }
}

const char *get_elf_type(Elf32_Half elf_type) {
    switch (elf_type) {
        case ET_NONE:
            return "NONE (No file type)";
        case ET_REL:
            return "REL (Relocatable file)";
        case ET_EXEC:
            return "EXEC (Executable file)";
        case ET_DYN:
            return "DYN (Shared object file)";
        case ET_CORE:
            return "CORE (Core file)";
        default:
            return "Unknown";
    }
}

const char *get_osabi_name(unsigned char osabi) {
    switch (osabi) {
        case ELFOSABI_SYSV:
            return "UNIX - System V";
        case ELFOSABI_HPUX:
            return "UNIX - HP-UX";
        case ELFOSABI_NETBSD:
            return "UNIX - NetBSD";
        case ELFOSABI_LINUX:
            return "UNIX - Linux";
        case ELFOSABI_SOLARIS:
            return "UNIX - Solaris";
        case ELFOSABI_AIX:
            return "UNIX - AIX";
        case ELFOSABI_IRIX:
            return "UNIX - IRIX";
        case ELFOSABI_FREEBSD:
            return "UNIX - FreeBSD";
        case ELFOSABI_TRU64:
            return "UNIX - TRU64";
        case ELFOSABI_MODESTO:
            return "Novell - Modesto";
        case ELFOSABI_OPENBSD:
            return "UNIX - OpenBSD";
        case ELFOSABI_ARM_AEABI:
            return "ARM EABI";
        case ELFOSABI_ARM:
            return "ARM";
        case ELFOSABI_STANDALONE:
            return "Standalone App";
        default:
            return "Unknown";
    }
}

void print_elf_header(Elf32_Ehdr *header) {
    int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", get_elf_class(header->e_ident[EI_CLASS]));
    printf("  Data:                              %s\n", get_elf_data(header->e_ident[EI_DATA]));
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", get_osabi_name(header->e_ident[EI_OSABI]));
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", get_elf_type(header->e_type));
    printf("  Entry point address:               0x%x\n", header->e_entry);
    printf("%d\n", header->e_shoff);
}

int main(int argc, char *argv[]) {
    char *file_path;
    int fd;
    Elf32_Ehdr header;
    ssize_t bytes_read;
    
    if (argc != 2) {
        printf("Usage: %s <elf_file>\n", argv[0]);
        return 1;
    }

    file_path = argv[1];

    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}
