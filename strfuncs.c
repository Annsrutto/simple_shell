#include "shell.h"
/**
 * str_len - Returns the length of a string
 * @str: the string to get the length of
 * Return: the length of @string
 */
size_t str_len(char *str)
{
	size_t length;

	for (length = 0; str[length] != '\0'; length++)
		;
	return (length);
}

/**
 * str_copy - Copies a string
 * @dest: Destination string
 * @source: Source string
 * Return: The pointer to dest
 */
char *str_copy(char *dest, char *source)
{
	char *original_dest = dest;

	while ((*dest++ = *source++) != '\0')
		;
	return (original_dest);
}

/**
 * str_concat- Joins two strings
 * @dest: The destination string
 * @source: The source string
 * Return: A pointer to dest.
 */
char *str_concat(char *dest, char *source)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; source[j] != '\0'; j++)
		dest[i + j] = source[j];
	dest[i + j] = '\0';
	return (dest);
}

/**
 * str_char_search - Finds a character in a string.
 * @str: The string to search.
 * @ctr: The character to locate.
 * Return: The first occurrence of 'ctr' in the string
 * or NULL if the character is not located.
 */
char *str_char_search(const char *str, char ctr)
{
	while (*str != ctr && *str != '\0')
	{
		str++;
	}
	if (*str == ctr)
		return ((char *)str);
	else
		return (NULL);
}

/**
 * str_compare_n - Compare two strings upto n characters.
 * @str1: The first string for comparison.
 * @str2: The second string for comparison.
 * @count: The number of characters to be compared.
 *
 * Return: The result between the first unmatching characters or 0.
 */
int str_compare_n(const char *str1, const char *str2, size_t count)
{
	size_t i;

	for (i = 0; i < count && (str1[i] || str2[i]); i++)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	return (0);
}
