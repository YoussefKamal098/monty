#include "monty.h"

/**
 * print_stack - Print the elements of a stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number (not used in this function)
 *
 * This function prints the elements of a
 * stack to the standard output (stdout).
 * It traverses the stack starting from the
 * head and prints each element's value followed by a newline.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
