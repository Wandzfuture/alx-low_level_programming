#include "main.h"

/**
 * create_file - functionn that Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails (-1), Otherwise (1).
 */

int create_file(const char *filename, char *text_content)
{
	int file_descrip, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	file_descrip = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bytes_written = write(file_descrip, text_content, content_length);

	if (file_descrip == -1 || bytes_written == -1)
	{
		return (-1);
	}

	close(file_descrip);

	return (1);
}
