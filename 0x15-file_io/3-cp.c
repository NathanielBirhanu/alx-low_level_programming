#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_usage - Prints the correct usage of the program.
 */
void error_usage(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * error_cant_read - Prints an error message when unable to read from a file.
 * @filename: The name of the file.
 */
void error_cant_read(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * error_cant_write - Prints an error message when unable to write to a file.
 * @filename: The name of the file.
 */
void error_cant_write(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * error_cant_close - Prints an error message when unable
 * to close a file descriptor.
 * @fd: The file descriptor.
 */
void error_cant_close(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, ret;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	/* Check the number of arguments */
	if (argc != 3)
		error_usage();

	/* Open the source file */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_cant_read(argv[1]);

	/* Open the destination file (create if it doesn't exist) */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_cant_write(argv[2]);

	/* Copy the contents of the source file to the destination file */
	do {
		bytes_read = read(fd_from, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			error_cant_read(argv[1]);

		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_cant_write(argv[2]);

	} while (bytes_read > 0);

	/* Close the file descriptors */
	ret = close(fd_from);
	if (ret == -1)
		error_cant_close(fd_from);

	ret = close(fd_to);
	if (ret == -1)
		error_cant_close(fd_to);

	return (0);
}
