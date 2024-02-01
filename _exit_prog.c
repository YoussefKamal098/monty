#include "monty.h"

/**
 * _exit_prog - Exit the Monty interpreter with a specific exit code
 * @code: Exit code to be passed to the exit function
 *
 * This function is responsible for freeing memory associated with
 * the Monty interpreter, specifically the stack,
 * and then exiting the program with the specified exit code.
 * It releases resources used by the program before terminating execution.
 */
void _exit_prog(int code)
{
	if (data)
		free_program_data(data);
	exit(code);
}
