#include "monty.h"

/**
 * execute_opcode - Execute Monty opcode based on opcode information
 * @info: Pointer to an opcode_info_t struct containing opcode information
 *
 * This function is responsible for executing Monty opcodes based on
 * the provided opcode information.
 * It uses a static array of instruction_t structures to match
 * the opcode and call the corresponding function to perform the operation.
 * If the opcode is not recognized,
 * it prints an error message and exits the program.
 *
 * Note: This function assumes the presence of a global variable named 'data',
 * which may store program-specific information.
 * Ensure that 'data' is declared and accessible
 * in the scope of this function.
 */
void execute_opcode(opcode_info_t *info)
{
	static instruction_t instructions[] = {
	    {"push", push},
	    {"pall", print_stack},
	    {NULL, NULL}};
	size_t i;

	if (info == NULL || data == NULL)
		_exit_prog(EXIT_FAILURE);

	if (strcmp(info->code, "stack") == 0)
	{
		data->push_mode = STACK_MODE;
		return;
	}

	if (strcmp(info->code, "queue") == 0)
	{
		data->push_mode = QUEUE_MODE;
		return;
	}

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(info->code, instructions[i].opcode) == 0)
		{
			instructions[i].f(&data->stack_head, info->line);
			return;
		}
	}

	print_error(EUNKOWN_INSTRUCTION, info->line, info->code);
	_exit_prog(EXIT_FAILURE);
}
