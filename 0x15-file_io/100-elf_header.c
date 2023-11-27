#include "main.h"

/**
 * print_error_and_exit - Print an error message to stderr and exit with status 98
 * @msg: The error message to be printed
 */
void print_error_and_exit(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_error - Print an error message to stderr
 * @msg: The error message to be printed
 */
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
}

/**
 * print_elf_header - Display information from the ELF header of a file
 * @filename: The name of the ELF file
 * @elf: Pointer to the ELF structure
 */
void print_elf_header(const char *filename, Elf *elf)
{
	GElf_Ehdr ehdr;
	unsigned char ident[EI_NIDENT];
	size_t read_size;

	read_size = read(elf_getbase(elf), ident, EI_NIDENT);
	if (read_size != EI_NIDENT)
	{
		ERROR_MSG("File is not an ELF");
		elf_end(elf);
		exit(98);
	}

	if (gelf_getehdr(elf, &ehdr) == NULL)
	{
		ERROR_MSG("gelf_getehdr");
		elf_end(elf);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");
	for (size_t i = 0; i < EI_NIDENT; ++i)
		printf("%02x%c", ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             %s\n", ehdr.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", ehdr.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", ehdr.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Others");
	printf("  ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);
	printf("  Type:                              0x%x (", ehdr.e_type);
	switch (ehdr.e_type)
	{
		case ET_NONE:
			printf("No file type");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("Unknown file type");
	}

	printf(")\n  Entry point address:               0x%lx\n", ehdr.e_entry);
}

/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 * 
 * Return: (0) on success, otherwise (1)
 */
int main(int argc, char **argv)
{
	int fd;
	Elf * elf;

	if (argc != 2)
		ERROR_EXIT("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || elf_version(EV_CURRENT) == EV_NONE || (elf = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
		ERROR_EXIT("File not found or not ELF");

	print_elf_header(argv[1], elf);

	elf_end(elf);
	close(fd);

	return (0);
}
