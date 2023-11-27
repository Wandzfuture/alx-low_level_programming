#include "main.h"

char *allocate_buffer();
void close_fd(int fd);

/**
 * allocate_buffer - function that allocates 1024 bytes to buffer.
 * @file: The name of the file buffer is storing characters for.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *allocate_buffer()
{
	char *buffer = malloc(1024 * sizeof(char));

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_fd - function that Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
	int status = close(fd);

	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: (0) on success.
 *
 * Description:
 * - Checks if the argument count is correct, otherwise exits with code 97.
 * - Opens the source file for reading, exits with code 98 if it fails.
 * - Opens/creates the destination file for writing, exits with code 99(fails).
 * - Reads data from the source file and writes it to the destination file.
 * - Exits with code 98 from the source file fails, or  99 if fails
 * - Closes the file descriptors and frees memory before exiting successfully.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer();
	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		close_fd(source_fd);
		exit(99);
	}

	do {
		bytes_read = read(source_fd, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			close_fd(source_fd);
			close_fd(dest_fd);
			exit(98);
		}

		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			close_fd(source_fd);
			close_fd(dest_fd);
			exit(99);
		}
	} while (bytes_read > 0);

	free(buffer);
	close_fd(source_fd);
	close_fd(dest_fd);

	return (0);
}
