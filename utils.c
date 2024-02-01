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

/**
 * create_stack_node - Create a new node for the stack
 * @n: Integer value to be stored in the new node
 *
 * This function creates a new node for the stack, initializes its values,
 * and returns a pointer to the created node. If memory allocation fails, it
 * prints an error message and exits the program.
 *
 * Return: Pointer to the newly created stack node.
 */
stack_t *create_stack_node(int n)
{
	stack_t *node;

	node = (stack_t *)malloc(sizeof(stack_t));

	if (node == NULL)
	{
		print_error(EMALLOC_FAILED);
		_exit_prog(EXIT_FAILURE);
	}

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}
