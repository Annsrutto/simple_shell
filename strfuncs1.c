#include "shell.h"

/**
 * str_compare - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: -ve value if str1 < str2, 0 if str1 == str2, else +ve.
 */
int str_compare(const char *str1, const char *str2)
{
	int index = 0;

	while (str1[index] == str2[index])
		index++;

	return (str1[index] - str2[index]);
}

/**
 * str_n_compare - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: -ve value if str1 < str2, 0 if str1 == str2, else +ve.
 */
int str_n_compare(const char *str1, const char *str2)
{
	int index;

	for (index = 0; str1[index] != '\0' || str2[index] != '\0'; index++)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
	}
	return (0);
}

/**
 * str_length - Calculate length of a string.
 * @str: Input string.
 * Return: Length of the string.
 */
int str_length(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * str_concat - Concatenate two strings.
 * @str1: First string.
 * @str2: Second string to be appended to first string.
 * Return: Pointer to the concatenated string; else NULL.
 */
char *str_concat(char *str1, char *str2)
{
	char *combined_str;
	int i, j;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";

	combined_str = malloc(str_length(str1) + str_length(str2) + 1);
	if (!combined_str)
		exit(0);

	for (i = 0; str1[i] != '\0'; i++)
		combined_str[i] = str1[i];
	for (j = 0; str2[j] != '\0'; j++)
		combined_str[i + j] = str2[j];
	combined_str[i + j] = '\0';

	return (combined_str);
}

