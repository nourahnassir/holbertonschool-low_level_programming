#include "main.h"

/**
 * create_file - Creates a file with specific permissions and writes text.
 * @filename: The name of the file to create.
 * @text_content: The NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_written = 0, len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		n_written = write(fd, text_content, len);
	}

	close(fd);

	if (n_written == -1 || n_written != len)
		return (-1);

	return (1);
}
