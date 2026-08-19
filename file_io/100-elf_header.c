#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints error message to stderr and exits with status 98.
 * @msg: The error message to print.
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
	    e_ident[2] != 'L' || e_ident[3] != 'F')
		print_error("Error: Not an ELF file");
}

/**
 * print_magic - Prints ELF magic numbers.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "" : " ");
	}
	printf("\n");
}

/**
 * print_class - Prints ELF class.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints ELF data encoding.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - Prints ELF version.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - Prints ELF OS/ABI.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
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
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64 UNIX\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abiversion - Prints ELF ABI version.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints ELF file type.
 * @e_type: ELF type value.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints ELF entry point address.
 * @e_entry: Entry point address value.
 * @e_ident: Pointer to the ELF magic numbers array.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	printf("  Entry point address:               ");
	if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("%#lx\n", e_entry);
	else
		printf("%#x\n", (unsigned int)e_entry);
}

/**
 * main - Displays information contained in the ELF header.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t ret;
	Elf64_Ehdr *header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't read file");

	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
	{
		close(fd);
		print_error("Error: Memory allocation failed");
	}

	ret = read(fd, header, sizeof(Elf64_Ehdr));
	if (ret == -1)
	{
		free(header);
		close(fd);
		print_error("Error: Can't read from file");
	}

	check_elf(header->e_ident);
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abiversion(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	if (close(fd) == -1)
	{
		close(fd);
		print_error("Error: Can't close fd");
	}

	return (0);
}
