#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/**
 * enum error_enum - Enumeration defines a set of error codes commonly used in
 * the context of a Monty interpreter program. Each code represents a
 * specific error condition that may occur during the execution of the program.
 *
 * @E_MONTY_FILE: (Value: 300): Indicates an error related to the Monty
 * bytecode file, Monty file not passed to program
 *
 * @E_OPEN_FILE: (Value: 301): Represents an error occurring while
 * attempting to open a file, indicating a failure in the file opening process.
 *
 * @E_UNKOWN_INSTRUCTION: (Value: 302): Signifies an error caused by
 * encountering an unknown or unsupported Monty opcode during program
 * execution.
 *
 * @E_MALLOC_FAILED: (Value: 303): Indicates a failure in dynamic memory
 * allocation, often triggered by the `malloc` function.
 *
 * @E_PUSH_INTEGER: (Value: 304): Denotes an error related to the `push`
 * opcode, specifically when attempting to push a non-integer value onto
 * the stack.
 *
 * @E_STACK_EMPTY: (Value: 305): Represents an error occurring when an
 * operation requiring elements from an empty stack is performed.
 *
 * @E_STACK_TOO_SHORT: (Value: 306): Indicates an error where the stack is
 * too short to perform a particular operation.
 *
 * @E_ZERO_DIVISION: (Value: 307): Signifies an error resulting from
 * attempting to perform division by zero.
 *
 * @E_RANGE: (Value: 308): Represents an error caused by a value falling
 * outside the valid range, indicating an overflow or underflow condition.
 */

typedef enum error_enum
{
	E_MONTY_FILE = 300,
	E_OPEN_FILE,
	E_UNKOWN_INSTRUCTION,
	E_MALLOC_FAILED,
	E_PUSH_INTEGER,
	E_STACK_EMPTY,
	E_STACK_TOO_SHORT,
	E_ZERO_DIVISION,
	E_RANGE
} error;

/**
 * struct error_handler_s - error handler for error messages
 * @code: error code
 * @handler: function that write error code message to stderr
 */
typedef struct error_handler_s
{
	error code;
	int (*handler)(va_list args);
} error_handler_t;

/* print_error.c */
void print_error(error code, ...);

/* errors_1.c */
int print_monty_file_error(va_list args);
int print_cannot_open_file_error(va_list args);
int print_unknown_instruction_error(va_list args);
int print_malloc_error(va_list args);
int print_push_integer_error(va_list args);

/* errors_2.c */
int print_stack_empty_error(va_list args);
int print_stack_too_short_error(va_list args);
int print_zero_division_error(va_list args);
int print_range_error(va_list args);

#endif /* ERROR_H_ */
