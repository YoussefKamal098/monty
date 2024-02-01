#include "error.h"

/**
 * print_stack_empty_error - Print an error message for an empty stack
 * @args: Variable arguments list containing opcode and line number
 *
 * This function prints an error message indicating that an operation
 * cannot be performed on an empty stack.
 *
 * @args: Variable arguments list containing opcode and line number.
 *
 * Return: Number of characters written (or a negative value on failure).
 */
int print_stack_empty_error(va_list args)
{
	char *opcode = va_arg(args, char *);
	int opcode_line_number = va_arg(args, int);
	int written_bytes;

	if (opcode == NULL)
		return (-1);

	if (strcmp(opcode, "pop") == 0)
		written_bytes = fprintf(stderr, "L%d: can't %s an empty stack\n",
					opcode_line_number, opcode);
	else
		written_bytes = fprintf(stderr, "L%d: can't %s, stack empty\n",
					opcode_line_number, opcode);

	return (written_bytes);
}

/**
 * print_stack_too_short_error - Print an error message for stack underflow
 * @args: Variable arguments list containing opcode and line number
 *
 * This function prints an error message indicating that a stack underflow
 * occurred, typically when an operation requires more elements on the stack
 * than are available.
 *
 * Return: Number of characters written (or a negative value on failure).
 */
int print_stack_too_short_error(va_list args)
{
	char *opcode = va_arg(args, char *);
	int opcode_line_number = va_arg(args, int);
	int written_bytes;

	if (opcode == NULL)
		return (-1);

	written_bytes = fprintf(stderr, "%d: can't %s, stack too short",
				opcode_line_number, opcode);

	return (written_bytes);
}
