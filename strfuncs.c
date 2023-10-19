#include "shell.h"

/**
 * str_tok - Tokenize a string into words.
 * @str: The input string.
 * Return: An array of tokens.
 */
char **str_tok(char *str)
{
	char **tokens;
	int num_tokens;

	num_tokens = count_words(str);
	if (num_tokens <= 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (num_tokens + 1));
	if (!tokens)
		return (NULL);
	str_extract(tokens, str);

	return (tokens);
}

/**
 * copy_word - Copies a word from a string.
 * @dest_len: The length of the destination string.
 * @src: The source string to extract the word from.
 * @dest: The destination to store the copied word.
 */
void copy_word(int dest_len, char *src, char **dest)
{
	int idx;

	*dest = malloc(sizeof(char) * (dest_len + 1));
	if (!(*dest))
	{
		perror("Error: malloc failed");
		free(dest);
		exit(0);
	}

	for (idx = 0; idx < dest_len; idx++)
		(*dest)[idx] = src[idx];
	(*dest)[idx] = '\0';
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to be converted.
 * Return: Converted integer value.
 */
int _atoi(char *str)
{
	int idx, sign;
	unsigned int result;

	result = idx = 0;
	sign = 1;

	while ((str[idx] < '0' || str[idx] > '9') && str[idx] != '\0')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	for (; str[idx] != '\0' && str[idx] >= '0' && str[idx] <= '9'; idx++)
	{
		result = result * 10 + (str[idx] - '0');
	}
	result *= sign;

	return (result);
}

