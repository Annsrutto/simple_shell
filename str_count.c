#include "shell.h"

/**
 * count_words - Function that counts the number of words in a string.
 * @s:pointer to the string.
 * Return: number of words in the string or -1 if there are no words.
 */
int count_words(char *s)
{
	unsigned int len, i;
	int total_words;

	if (s == NULL || *s == '\0')
		return (-1);

	total_words = i = len = 0;

	if (s[1] == '\0' && *s == ' ')
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i + 1] == '\0')
		{
			if (s[i] != ' ' )
				total_words = 1;
			if (total_words)
			{
				len += 1;
				total_words = 0;
			}
			i += 1;
			continue;
		}
		else
			total_words = 1;
		i += 1;
	}

	return (len);
}

