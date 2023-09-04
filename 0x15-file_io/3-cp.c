#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_and_exit - Prints the error message and exits the program.
 * @code: The exit code.
 * @message: The error message to print.
 */
void error_and_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char **argv)
{
	int file_from, file_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_and_exit(97, "Usage: cp file_from file_to");

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_and_exit(98, dprintf(STDERR_FILENO,
					   "Error: Can't read from file %s", argv[1]));

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_to == -1)
		error_and_exit(99, dprintf(STDERR_FILENO,
					   "Error: Can't write to %s", argv[2]));

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_and_exit(99, dprintf(STDERR_FILENO,
						   "Error: Can't write to %s", argv[2]));
	}

	if (bytes_read == -1)
		error_and_exit(98, dprintf(STDERR_FILENO,
					   "Error: Can't read from file %s", argv[1]));

	if (close(file_from) == -1)
		error_and_exit(100, dprintf(STDERR_FILENO,
					    "Error: Can't close fd %d", file_from));

	if (close(file_to) == -1)
		error_and_exit(100, dprintf(STDERR_FILENO,
					    "Error: Can't close fd %d", file_to));

	return (0);
}
