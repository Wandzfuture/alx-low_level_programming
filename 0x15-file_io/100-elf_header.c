#include "main.h"

/**
 * get_class - Get the class information based on e_ident value
 * @e_ident: The e_ident value representing class information
 *
 * Return: Corresponding class information as a string
 */
const char *get_class(unsigned char e_ident)
{
        switch (e_ident)
        {
                case 0:
                        return ("None");
                case 1:
                        return ("32-bit");
                case 2:
                        return ("64-bit");
                default:
                        return ("Invalid");
        }
}

/**
 * get_data - Get the data information based on e_ident value
 * @e_ident: The e_ident value representing data information
 *
 * Return: Corresponding data information as a string
 */
 const char *get_data(unsigned char e_ident)
 {
 	switch (e_ident)
 	{
 		case 0:
 			return ("None");
 		case 1:
 			return ("Little Endian");
 		case 2:
 			return ("Big Endian");
 		default:
 			return ("Invalid");
 	}
 }

 /**
  *get_osabi - Get the OS/ABI information based on e_ident value
  *@e_ident: The e_ident value representing OS/ABI information
  *
  *Return: Corresponding OS/ABI information as a string
  */
 const char *get_osabi(unsigned char e_ident)
 {
 	switch (e_ident)
 	{
 		case 0:
 			return ("System V");
 		case 1:
 			return ("HP-UX");
 		case 2:
 			return ("NetBSD");
 		case 3:
 			return ("Linux");
 		case 4:
 			return ("GNU Hurd");
 		case 5:
 			return ("86Open common base");
 		case 6:
 			return ("ARM");
 		case 7:
 			return ("STMicroelectronics ST");
 		case 8:
 			return ("Motorola 68K");
 		case 9:
 			return ("Motorola 88K");
 		case 10:
 			return ("Intel 80386");
 		case 11:
 			return ("MIPS RS3000 big-endian");
 		case 12:
 			return ("IBM System/370");
 		case 13:
 			return ("MIPS RS3000 little-endian");
 		case 15:
 			return ("SPARC");
 		case 16:
 			return ("OpenRISC 32-bit");
 		case 17:
 			return ("PowerPC 32-bit");
 		case 18:
 			return ("PowerPC 64-bit");
 		case 19:
 			return ("S390");
 		case 20:
 			return ("SPU");
 		case 21:
 			return ("Nvidia CUDA");
 		case 22:
 			return ("TILEPro");
 		case 23:
 			return ("MIPS RS6000");
 		case 24:
 			return ("AMD GPU");
 		case 25:
 			return ("Infineon Technologies");
 		case 26:
 			return ("ARM 64-bit");
 		case 27:
 			return ("Cypress PSoC 5");
 		case 28:
 			return ("Freescale/NXP RISC-V");
 		case 29:
 			return ("Netronome Flow Management");
 		case 30:
 			return ("Barefoot Tofino");
 		case 31:
 			return ("Cavium Octeon");
 		case 65:
 			return ("OpenPOWER");
 		case 66:
 			return ("AMD x86-64");
 		case 255:
 			return ("Embedded RTOS ABI");
 		default:
 			return ("Unknown");
 	}
 }

/**
 * main - Entry point of the program, reads and displays information from ELF header
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: (0) on success, otherwise (1)
 */
int main(int argc, char *argv[])
{
	int fd;
	struct stat sb;
	ElfHeader * eh;

	if (argc != 2)
	{
		printf("Usage: %s < elf file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	if (fstat(fd, &sb) == -1)
	{
		perror("fstat");
		return (1);
	}

	eh = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (eh == MAP_FAILED)
	{
		perror("mmap");
		return (1);
	}

	if (memcmp(eh->e_ident, MAGIC, 4) != 0)
	{
		printf("Invalid ELF file\n");
		return (1);
	}

	printf("Class: %s\n", get_class(eh->e_ident[EI_CLASS]));
	printf("Data: %s\n", get_data(eh->e_ident[EI_DATA]));
	printf("Version: %u\n", eh->e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n", get_osabi(eh->e_ident[EI_OSABI]));
	printf("ABI Version: %u\n", eh->e_ident[EI_ABIVERSION]);
	printf("Type: %u\n", eh->e_type);
	printf("Machine: %u\n", eh->e_machine);
	printf("Version: %u\n", eh->e_version);
	printf("Entry point: %u\n", eh->e_entry);
	printf("Program header offset: %u\n", eh->e_phoff);
	printf("Section header offset: %u\n", eh->e_shoff);
	printf("Flags: %u\n", eh->e_flags);
	printf("ELF header size: %u\n", eh->e_ehsize);
	printf("Program header entry size: %u\n", eh->e_phentsize);
	printf("Program header count: %u\n", eh->e_phnum);
	printf("Section header entry size: %u\n", eh->e_shentsize);
	printf("Section header count: %u\n", eh->e_shnum);
	printf("Section header string table index: %u\n", eh->e_shstrndx);

	munmap(eh, sb.st_size);
	close(fd);

	return (0);
}
