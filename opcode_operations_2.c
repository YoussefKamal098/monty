#include "monty.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: A double pointer to the head of the stack.
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
		print_error(E_STACK_EMPTY, "pop", line_number);
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
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where the
 * swap operation is called.
 *
 * This function swaps the values of the top two elements on the stack.
 * If the stack contains fewer than two elements,
 * it prints an error message and exits the program with a failure status.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element = *stack;
	stack_t *second_element = first_element ? first_element->next : NULL;
	int tmp;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_element == NULL || second_element == NULL)
	{
		print_error(E_STACK_TOO_SHORT, "swap", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	tmp = first_element->n;
	first_element->n = second_element->n;
	second_element->n = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where the
 * add operation is called.
 *
 * This function adds the values of the top two elements on
 * the stack and replaces the top element with the result.
 * If the stack contains fewer than two elements, it prints
 * an error message and exits the program with a failure status.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element = *stack;
	stack_t *second_element = first_element ? first_element->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_element == NULL || second_element == NULL)
	{
		print_error(E_STACK_TOO_SHORT, "add", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_element->n = second_element->n + first_element->n;
	pop(stack, line_number);
}

/**
 * sub - Subtracts the top element from the second element of the stack.
 *
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where the
 * sub operation is called.
 *
 * This function subtracts the value of the top element from the second element
 * on the stack and replaces the second element with the result.
 * If the stack contains fewer than two elements,
 * it prints an error message and exits the program with a failure status.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element = *stack;
	stack_t *second_element = first_element ? first_element->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_element == NULL || second_element == NULL)
	{
		print_error(E_STACK_TOO_SHORT, "sub", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_element->n = second_element->n - first_element->n;
	pop(stack, line_number);
}

/**
 * _div - Divides the second element by the top element of the stack.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the div operation is called.
 *
 * This function divides the value of the top element by
 * the second element on the stack and replaces the
 * second element with the result.
 * If the stack contains fewer than two elements, it prints an error message
 * and exits the program with a failure status. If the top element is zero,
 * it prints a zero division error message and
 * exits the program with a failure status.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element = *stack;
	stack_t *second_element = first_element ? first_element->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_element == NULL || second_element == NULL)
	{
		print_error(E_STACK_TOO_SHORT, "div", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if (first_element->n == 0)
	{
		print_error(E_ZERO_DIVISION, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_element->n = second_element->n / first_element->n;
	pop(stack, line_number);
}
