#include "monty.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the pop operation is called.
 *
 * This function removes the top element from the stack.
 * If the stack is empty, it prints an error message and exits the
 * program with a failure status. If the stack becomes
 * empty after the pop operation, the stack pointer is set to NULL.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*stack == NULL)
	{
		print_error(ESTACK_EMPTY, "pop", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
