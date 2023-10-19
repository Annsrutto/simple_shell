#include "shell.h"

static char *input_buffer;
static size_t buffer_capacity;

/**
 * _getline - Get line input from user.
 * @lptr: Store the address of the line of text read.
 * @m: Size of the buffer.
 * @strm: Where the input is read from.
 *
 * Return: Number of characters read on success and -1 on failure.
 */
ssize_t _getline(char **lptr, size_t *m, FILE *strm)
{
	size_t idx;
	char ch;
	ssize_t bytes_read;
	int file_descriptor = fileno(strm);
	struct stat file_info;

	idx = 0;

	initialize_buffer(lptr, m);

	if (fstat(file_descriptor, &file_info) == -1)
	{
		perror("Failed to get file information");
		return (-1);
	}
	while ((bytes_read = read(file_descriptor, &ch, 1)) > 0)
	{
		expand_buffer(lptr, m, idx);
		(*lptr)[idx++] = ch;
		if (ch == '\n')
		{
			(*lptr)[idx] = '\0';
			return (idx);
		}
	}
	if (bytes_read < 0)
	{
		perror("Read error");
		return (-1);
	}
	if (idx == 0)
		return (-1);
	(*lptr)[idx] = '\0';
	return (idx);
}

/**
 * initialize_buffer - Allocates initial buffer.
 * @lptr: Pointer to the line buffer.
 * @m: Pointer to the size of the buffer.
 */
void initialize_buffer(char **lptr, size_t *m)
{
	if (*lptr == NULL || *m == 0)
	{
		if (input_buffer == NULL)
		{
			buffer_capacity = 128;
			input_buffer = (char *)malloc(sizeof(buffer_capacity));
			if (input_buffer == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			else
			{
				free(*lptr);
			}
		}
		*m = buffer_capacity;
		*lptr = input_buffer;
	}
}

/**
 * expand_buffer - Expands the buffer.
 * @lptr: Pointer to the line buffer.
 * @m: Pointer to the size of the buffer.
 * @idx: Current index in the buffer.
 */
void expand_buffer(char **lptr, size_t *m, size_t idx)
{
	char *temp_ptr;

	if (idx >= *m - 1)
	{
		*m *= 2;
		temp_ptr = (char *)realloc(*lptr, *m);
		if (temp_ptr == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		*lptr = temp_ptr;
	}
}

