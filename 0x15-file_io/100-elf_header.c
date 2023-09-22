#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Print error message and exit with status code 98
 * @message: The error message
 *
 * Description: Prints the error message to stderr and exits with status code 98.
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * print_elf_header - Print the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 *
 * Description: Prints the information contained in the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:                             %s\n",
	       (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("Data:                              %s\n",
	       (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
	       "2's complement, big endian");
	printf("Version:                           %d (current)\n",
	       header->e_ident[EI_VERSION]);

	printf("OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX System V ABI");
		break;
	case ELFOSABI_HPUX:
		printf("HP-UX");
		break;
	case ELFOSABI_NETBSD:
		printf("NetBSD");
		break;
	case ELFOSABI_LINUX:
		printf("Linux");
		break;
	case ELFOSABI_SOLARIS:
		printf("Solaris");
		break;
	case ELFOSABI_AIX:
		printf("AIX");
		break;
	case ELFOSABI_IRIX:
		printf("IRIX");
		break;
	case ELFOSABI_FREEBSD:
		printf("FreeBSD");
		break;
	case ELFOSABI_TRU64:
		printf("TRU64 UNIX");
		break;
	case ELFOSABI_MODESTO:
		printf("Novell Modesto");
		break;
	case ELFOSABI_OPENBSD:
		printf("OpenBSD");
		break;
	default:
		printf("Unknown");
		break;
	}
	printf("\n");

	printf("ABI Version:                       %d\n",
	       header->e_ident[EI_ABIVERSION]);

	printf("Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("None (No file type)");
		break;
	case ET_REL:
		printf("Relocatable object file");
		break;
	case ET_EXEC:
		printf("Executable file");
		break;
	case ET_DYN:
		printf("Shared object file");
		break;
	case ET_CORE:
		printf("Core file");
		break;
	default:
		printf("Unknown");
		break;
	}
	printf("\n");
	printf("Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Program entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, 98 on error
 *
 * Description: The main function of the program. Reads an ELF header from a file
 * specified as a command-line argument and prints its information.
 */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;
	ssize_t n;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Failed to open the file");

	n = read(fd, &header, sizeof(header));
	if (n != sizeof(header))
		print_error("Failed to read the ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	print_elf_header(&header);

	close(fd);
	return 0;
}
