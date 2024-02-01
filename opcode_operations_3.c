#include "monty.h"

/**
 * mul - Multiplies the top element by the second element of the stack.
 *
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the mul operation is called.
 *
 * This function multiplies the value of the top element by
 * the second element on the stack and replaces the
 * second element with the result. If the stack contains fewer
 * than two elements, it prints an error message and
 * exits the program with a failure status.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first_top = *stack;
	stack_t *second_top = first_top ? first_top->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_top == NULL || second_top == NULL)
	{
		print_error(ESTACK_TOO_SHORT, "mul", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_top->n = second_top->n * first_top->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second element by
 * the top element of the stack.
 *
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the mod operation is called.
 *
 * This function computes the modulus of the second element by
 * the top element on the stack and replaces the
 * second element with the result. If the stack contains fewer
 * than two elements, it prints an error message and exits the
 * program with a failure status. If the top element is 0,
 * it prints a zero division error and exits the program with a failure status.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first_top = *stack;
	stack_t *second_top = first_top ? first_top->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_top == NULL || second_top == NULL)
	{
		print_error(ESTACK_TOO_SHORT, "mod", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if (first_top->n == 0)
	{
		print_error(EZERO_DIVISION, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_top->n = second_top->n % first_top->n;
	pop(stack, line_number);
}