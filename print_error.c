#include "error.h"

/**
 * print_error - Print error message based on error code
 * @code: Integer representing the error code
 * @...: Variable arguments depending on the error code
 *
 * This function prints an error message based on the provided error code.
 * It uses a static array of error_handler_t structures to match the error
 * code with the corresponding error handling function. The variable arguments
 * depend on the specific error code and are passed accordingly.
 */
void print_error(ERROR_CODE code, ...)
{
	static error_handler_t error_handler[] = {
	    {E_MONTY_FILE, print_monty_file_error},
	    {E_OPEN_FILE, print_cannot_open_file_error},
	    {E_UNKOWN_INSTRUCTION, print_unknown_instruction_error},
	    {E_MALLOC_FAILED, print_malloc_error},
	    {E_PUSH_INTEGER, print_push_integer_error},
	    {E_STACK_EMPTY, print_stack_empty_error},
	    {E_STACK_TOO_SHORT, print_stack_too_short_error},
	    {E_ZERO_DIVISION, print_zero_division_error},
	    {E_RANGE, print_range_error},
	    {0, NULL},
	};
	size_t i;
	va_list args;
	int ret;

	va_start(args, code);
	for (i = 0; error_handler[i].handler; i++)
	{
		if (code == error_handler[i].code)
		{
			ret = error_handler[i].handler(args);
			va_end(args);

			if (ret == EOF)
				perror("Error writing to stderr");
			break;
		}
	}

	if (error_handler[i].handler == NULL)
		fprintf(stderr, "Unknown error code: %d\n", code);
}
