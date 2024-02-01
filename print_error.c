#include "error.h"

/**
 * print_error - Print error message based on error code
 * @error_code: Integer representing the error code
 * @...: Variable arguments depending on the error code
 *
 * This function prints an error message based on the provided error code.
 * It uses a static array of error_handler_t structures to match the error
 * code with the corresponding error handling function. The variable arguments
 * depend on the specific error code and are passed accordingly.
 */
void print_error(int error_code, ...)
{
	static error_handler_t error_handler[] = {
	    {EMONTY_FILE, print_monty_file_error},
	    {EOPEN_FILE, print_cannot_open_file_error},
	    {EUNKOWN_INSTRUCTION, print_unknown_instruction_error},
	    {EMALLOC_FAILED, print_malloc_error},
	    {EPUSH_INTEGER, print_push_integer_error},
	    {ESTACK_EMPTY, print_stack_empty_error},
	    {ESTACK_TOO_SHORT, print_stack_too_short_error},
	    {EZERO_DIVISION, print_zero_division_error},
	    {0, NULL},
	};
	size_t i;
	va_list args;
	int ret;

	va_start(args, error_code);
	for (i = 0; error_handler[i].handler; i++)
	{
		if (error_code == error_handler[i].code)
		{
			ret = error_handler[i].handler(args);
			va_end(args);

			if (ret == EOF)
			{
				perror("Error writing to stderr");
				_exit_prog(EXIT_FAILURE);
			}
			break;
		}
	}
}
