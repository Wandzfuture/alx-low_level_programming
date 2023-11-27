#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL = (-1).
 * If the file doesn't exist the user lacks write permissions = (-1),
 * Otherwise (1).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descrip, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	file_descrip = open(filename, O_WRONLY | O_APPEND);
	bytes_written = write(file_descrip, text_content, content_length);

	if (file_descrip == -1 || bytes_written == -1)
	{
		return (-1);
	}

	close(file_descrip);

	return (1);
}
