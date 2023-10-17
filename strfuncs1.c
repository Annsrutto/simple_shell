#include "shell.h"
/**
 * str_compare - compares two strings
 * @str1: The first string
 * @str2: The second string
 * Return: The difference
 */
int str_compare(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}

/**
 * str_exclude_span - Calculates the length of str1
 * which contain characters not from str2.
 *
 * @str1: The string to be examined.
 * @str2: The characters to be excluded.
 *
 * Return: The length of the segment of str1 not containing
 * characters from str2.
 */
int str_exclude_span(char *str1, char *str2)
{
	int length = 0;
	int i;

	while (str1[length] != '\0')
	{
		for (i = 0; str2[i] != '\0'; i++)
		{
			if (str1[length] == str2[i])
				return (length);
		}
		length++;
	}
	return (length);
}

/**
 * str_duplicate - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to copy of str, or NULL if memory allocation fails.
 */
char *str_duplicate(const char *str)
{
	int length = 0;
	int i;
	char *duplicate_str;

	if (str == NULL)
		return (NULL);
	while (str[length] != '\0')
		length++;
	duplicate_str = (char *)malloc(length + 1);

	if (duplicate_str == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
	{
		duplicate_str[i] = str[i];
	}
	duplicate_str[length] = '\0';
	return (duplicate_str);
}

/**
 * _atoi - Converts a string to an integer
 * @str: The string to convert
 * Return: The converted integer
 */
int _atoi(char *str)
{
	int sign = 1;
	int result = 0;
	int num_value;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			num_value = str[i] - '0';
			result = result * 10 + sign * num_value;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
		}
	}
	return (result);
}
