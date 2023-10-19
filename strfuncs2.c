#include "shell.h"

/**
 * str_extract - Function that extracts words from a string.
 * @word_array: Array to store extracted words.
 * @str: Pointer to the input string.
 * Return: array of words
 */
void str_extract(char **word_array, char *str)
{
	int i, index1, total_words, len;

	len = i = index1 = total_words = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i + 1] == '\0')
		{
			if (str[i] != ' ')
			{
				i++;
				total_words = 1;
			}

			if (total_words)
			{
				copy_substring_to_array(i - index1, str + index1, word_array + len);
				if (!word_array + len)
					exit(0);
				len += 1;
				index = i + 1;
				total_words = 0;
			}

			if (str[i] == '\0')
				continue;
			i += 1;
			index += 1;
			continue;
		}
		else
		{
			if (!total_words)
				index = i;
			total_words = 1;
		}
		i += 1;
	}
	word_array[len] = NULL;
}

/**
 * copy_substring_to_array - Copies a substring into a word array.
 * @len: Length of substring.
 * @substr: Pointer to the substring.
 * @dest: Pointer to the destination in the array.
 */
void copy_substring_to_array(int len, char *substr, char **dest)
{
	int j;

	*dest = malloc(sizeof(char) * (len + 1));
	if (!(*dest))
	{
		perror("Error: malloc\n");
		free(dest);
		exit(0);
	}

	for (j = 0; j < len; j++)
		(*dest)[j] = substr[j];
	(*dest)[j] = '\0';
}

