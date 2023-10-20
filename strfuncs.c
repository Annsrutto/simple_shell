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
			if (s[i] != ' ')
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

