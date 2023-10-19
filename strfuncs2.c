#include "shell.h"

/**
 * str_span - Determines the length of the initial portion of str1
 * which only consists of characters from str2.
 * @str1: The main string to be examined.
 * @str2: The string containing characters to match.
 * Return: The length of the initial portion of str1.
 */
size_t str_span(const char *str1, const char *str2)
{
	const char *initial = str1;
	const char *substr;
	bool character_match;

	while (*initial != '\0')
	{
		character_match = false;
		substr = str2;

		while (*substr != '\0')
		{
			if (*initial == *substr)
			{
				character_match = true;
				break;
			}
			substr++;
		}
		if (!character_match)
			break;
		initial++;
	}
	return (initial - str1);
}

