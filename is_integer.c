#include "monty.h"

/**
 * is_integer - Check if a string represents a valid integer
 * @str: Pointer to a string to be checked
 *
 * This function checks if a given string represents a valid integer. It
 * examines each character in the string and verifies whether it forms a
 * valid integer. The function returns true if the string is a valid integer,
 * and false otherwise.
 * Return: True if the string is a valid integer, false otherwise.
 */

bool is_integer(char *str)
{
	size_t i;

	if (str == NULL)
		return (false);

	if (str[0] == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
		if (isdigit(str[i]) == 0)
			return (false);

	return (true);
}
