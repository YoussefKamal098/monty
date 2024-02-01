#include "error.h"

/**
 * monty_file_error - Handle Monty file error and print usage message
 * @args: Variable arguments (not used in this function)
 *
 * This function serves as an error handler for the situation when an
 * incorrect Monty file is provided. It prints a usage message to the
 * standard error stream (stderr) indicating the correct usage of the
 * Monty interpreter.
 *
 * Return: The number of characters printed (excluding the null byte),
 * or a negative value if an error occurs during printing.
 */
int monty_file_error(va_list args)
{
	(void)args;
	return (fprintf(stderr, "USAGE: monty file\n"));
}

/**
 * cannot_open_file_error - Handle file opening error and print error message
 * @args: Variable arguments including the file path
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters an error while attempting to open a file. It takes
 * the file path as a variable argument and prints an error message to the
 * standard error stream (stderr).
 *
 * Return: The number of characters printed (excluding the null byte),
 * or a negative value if an error occurs during printing.
 */
int cannot_open_file_error(va_list args)
{
	int written_bytes;
	char *file_path = va_arg(args, char *);

	written_bytes = fprintf(stderr, "Error: Can't open file %s\n", file_path);

	return (written_bytes);
}

/**
 * unknown_instruction_error - Handle unknown instruction error and
 * print message
 * @args: Variable arguments including the line number and opcode
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters an unknown instruction in the Monty byte code file.
 * It takes variable arguments including the line number and opcode, and prints
 * an error message to the standard error stream (stderr).
 *
 * Return: The number of characters printed (excluding the null byte),
 * or a negative value if an error occurs during printing.
 */
int unknown_instruction_error(va_list args)
{
	int line_num = va_arg(args, int);
	char *opcode = va_arg(args, char *);
	int written_bytes;

	written_bytes = fprintf(stderr,
				"L%d: unknown instruction %s\n", line_num, opcode);

	return (written_bytes);
}

/**
 * malloc_error - Handle memory allocation error and print error message
 * @args: Variable arguments (not used in this function)
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters a memory allocation failure (malloc). It prints an
 * error message to the standard error stream (stderr).
 *
 * Return: The number of characters printed (excluding the null byte),
 * or a negative value if an error occurs during printing.
 */
int malloc_error(va_list args)
{
	(void)args;
	return (fprintf(stderr, "Error: malloc failed\n"));
}

/**
 * push_integer_error - Handle push integer error and print usage message
 * @args: Variable arguments including the line number
 *
 * This function serves as an error handler for the situation when the Monty
 * interpreter encounters an error while attempting to push an integer onto
 * the stack. It takes variable arguments including the line number and prints
 * a usage message to the standard error stream (stderr).
 *
 * Return: The number of characters printed (excluding the null byte),
 * or a negative value if an error occurs during printing.
 */
int push_integer_error(va_list args)
{
	int line_num = va_arg(args, int);
	int written_bytes;

	written_bytes = fprintf(stderr, "L%d: usage: push integer\n", line_num);

	return (written_bytes);
}
