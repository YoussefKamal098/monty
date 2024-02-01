#include "error.h"

/**
 * print_stack_empty_error - Print an error message for an empty stack
 * @args: Variable arguments list containing opcode and line number
 *
 * This function prints an error message indicating that an operation
 * cannot be performed on an empty stack.
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_stack_empty_error(va_list args)
{
	char *opcode = va_arg(args, char *);
	unsigned int opcode_line_number = va_arg(args, unsigned int);
	int written_bytes;

	if (opcode == NULL)
		return (-1);

	if (strcmp(opcode, "pop") == 0)
		written_bytes = fprintf(stderr, "L%u: can't %s an empty stack\n",
					opcode_line_number, opcode);
	else
		written_bytes = fprintf(stderr, "L%u: can't %s, stack empty\n",
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
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_stack_too_short_error(va_list args)
{
	char *opcode = va_arg(args, char *);
	unsigned int opcode_line_number = va_arg(args, unsigned int);
	int written_bytes;

	if (opcode == NULL)
		return (-1);

	written_bytes = fprintf(stderr, "L%u: can't %s, stack too short\n",
				opcode_line_number, opcode);

	return (written_bytes);
}

/**
 * print_zero_division_error - Prints a zero division error message to stderr.
 * @args: A variable argument list containing additional parameters.
 *
 * This function is responsible for printing a
 * zero division error message to the standard error stream (stderr).
 * It extracts the opcode line number from the variable argument list
 * and constructs the error message accordingly.
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_zero_division_error(va_list args)
{
	unsigned int opcode_line_number = va_arg(args, unsigned int);
	int written_bytes;

	written_bytes = fprintf(stderr, "L%u: division by zero\n",
				opcode_line_number);

	return (written_bytes);
}

/**
 * print_range_error - Print an error message for out-of-range value.
 * @args: A variable argument list containing opcode and line number.
 *
 * This function is used to print an error message when a value is out of range
 * for a specific opcode at a given line number.
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_range_error(va_list args)
{
	char *opcode = va_arg(args, char *);
	unsigned int opcode_line_number = va_arg(args, unsigned int);
	int written_bytes;

	if (opcode == NULL)
		return (-1);

	written_bytes = fprintf(stderr, "L%u: can't %s, value out of range\n",
				opcode_line_number, opcode);

	return (written_bytes);
}
