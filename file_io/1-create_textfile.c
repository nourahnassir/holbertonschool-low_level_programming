#include "main.h"

/**
 * create_textfile - Creates a text file and prints text.
 * @filename: The name of the file to create.
 * @text_content: The NULL terminated string to write to the file.
 *
 * Return: The number of letters printed, or 0 on failure.
 */
int create_textfile(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_written = 0, len = 0;

	if (!filename)
		return (0);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (0);

	if (text_content)
	{
		while (text_content[len])
			len++;
		n_written = write(fd, text_content, len);
	}

	close(fd);

	if (n_written == -1 || n_written != len)
		return (0);

	return (n_written);
}
