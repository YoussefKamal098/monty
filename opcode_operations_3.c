#include "monty.h"

/**
 * mul - Multiplies the top element by the second element of the stack.
 *
 * @stack: A double pointer to the head of the stack.
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
	stack_t *first_element = *stack;
	stack_t *second_element = first_element ? first_element->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_element == NULL || second_element == NULL)
	{
		print_error(E_STACK_TOO_SHORT, "mul", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_element->n = second_element->n * first_element->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second element by
 * the top element of the stack.
 *
 * @stack: A double pointer to the head of the stack.
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
	stack_t *first_element = *stack;
	stack_t *second_element = first_element ? first_element->next : NULL;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (first_element == NULL || second_element == NULL)
	{
		print_error(E_STACK_TOO_SHORT, "mod", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if (first_element->n == 0)
	{
		print_error(E_ZERO_DIVISION, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	second_element->n = second_element->n % first_element->n;
	pop(stack, line_number);
}

/**
 * pchar - Print the ASCII character equivalent of the top element
 * of the stack.
 *
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the pchar operation is called.
 *
 * This function prints the ASCII character equivalent of the top element of
 * the stack. It expects a non-empty stack and checks if the top element is
 * within the ASCII range before printing the character to the standard output.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*stack == NULL)
	{
		print_error(E_STACK_EMPTY, "pchar", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if (!isascii((*stack)->n))
	{
		print_error(E_RANGE, "pchar", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Print the string contained in the stack, starting from the top.
 *
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the pstr operation is called. (not used in this function)
 *
 * This function prints the string contained in the stack, starting from the
 * top. It expects a non-empty stack and prints characters one by one until it
 * reaches a null byte (0) or encounters a non-ASCII character.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	curr = *stack;

	while (curr)
	{
		if (curr->n == 0)
			break;
		if (!isascii((curr)->n))
			break;
		putchar(curr->n);
		curr = curr->next;
	}

	putchar('\n');
}

/**
 * rotl - Rotate the stack to the top.
 * @stack: A double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file where
 * the rotl operation is called. (not used in this function)
 *
 * This function rotates the stack to the top by moving the top element to
 * the bottom. It uses a double-linked list as the stack.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;

	(void)line_number;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tmp = (*stack)->n;

	pop(stack, line_number);
	push_queue(stack, tmp);
}
