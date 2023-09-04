#include "main.h"
/**
 * create_file - Creates a file with the specified filename
 *               and writes the given text content into it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write into the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, i;
	mode_t permissions = S_IRUSR | S_IWUSR; /* rw------- */

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;

		bytes_written = write(file_descriptor, text_content, i);
		if (bytes_written == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}
