#include "monty.h"

/**
 * rotr - Rotate the stack to the bottom.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the rotr operation is called. (not used in this function)
 *
 * This function rotates the stack to the bottom by moving the last element to
 * the top. It uses a double-linked list as the stack.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	curr = *stack;

	while (curr->next)
		curr = curr->next;

	curr->next = *stack;
	curr->prev->next = NULL;
	curr->prev = NULL;

	(*stack)->prev = curr;
	*stack = curr;
}
