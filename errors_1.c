#include "error.h"

/**
 * print_monty_file_error - Handle Monty file error and print usage message
 * @args: Variable arguments (not used in this function)
 *
 * This function serves as an error handler for the situation when an
 * incorrect Monty file is provided. It prints a usage message to the
 * standard error stream (stderr) indicating the correct usage of the
 * Monty interpreter.
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_monty_file_error(va_list args)
{
	(void)args;
	return (fprintf(stderr, "USAGE: monty file\n"));
}

/**
 * print_cannot_open_file_error - Handle file opening error and
 * print error message
 * @args: Variable arguments including the file path
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters an error while attempting to open a file. It takes
 * the file path as a variable argument and prints an error message to the
 * standard error stream (stderr).
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_cannot_open_file_error(va_list args)
{
	char *file_path = va_arg(args, char *);
	int written_bytes;

	if (file_path == NULL)
		return (-1);

	written_bytes = fprintf(stderr, "Error: Can't open file %s\n", file_path);

	return (written_bytes);
}

/**
 * print_unknown_instruction_error - Handle unknown instruction error and
 * print message
 * @args: Variable arguments including the line number and opcode
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters an unknown instruction in the Monty byte code file.
 * It takes variable arguments including the line number and opcode, and prints
 * an error message to the standard error stream (stderr).
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_unknown_instruction_error(va_list args)
{
	char *opcode = va_arg(args, char *);
	unsigned int opcode_line_number = va_arg(args, unsigned int);
	int written_bytes;

	if (opcode == NULL)
		return (-1);

	written_bytes = fprintf(stderr,
				"L%u: unknown instruction %s\n", opcode_line_number, opcode);

	return (written_bytes);
}

/**
 * print_malloc_error - Handle memory allocation error and print error message
 * @args: Variable arguments (not used in this function)
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters a memory allocation failure (malloc). It prints an
 * error message to the standard error stream (stderr).
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_malloc_error(va_list args)
{
	(void)args;
	return (fprintf(stderr, "Error: malloc failed\n"));
}

/**
 * print_push_integer_error - Handle push integer error and print usage message
 * @args: Variable arguments including the line number
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters an error while attempting to push an integer onto
 * the stack. It takes variable arguments including the line number and prints
 * a usage message to the standard error stream (stderr).
 *
 * Return: The number of bytes written to stderr or -1 on failure.
 */
int print_push_integer_error(va_list args)
{
	unsigned int opcode_line_number = va_arg(args, unsigned int);
	int written_bytes;

	written_bytes = fprintf(stderr, "L%u: usage: push integer\n",
				opcode_line_number);

	return (written_bytes);
}
