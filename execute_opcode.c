#include "monty.h"

void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

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
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {"add", add},
	    {"nop", NULL},
	    {"sub", sub},
	    {"div", _div},
	    {"stack", stack},
	    {"queue", queue},
	    {NULL, NULL}};
	size_t i;

	if (info == NULL || data == NULL)
		_exit_prog(EXIT_FAILURE);

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(info->code, instructions[i].opcode) == 0)
		{
			if (instructions[i].f)
				instructions[i].f(&data->stack_head, info->line);
			return;
		}
	}

	print_error(EUNKOWN_INSTRUCTION, info->code, info->line);
	_exit_prog(EXIT_FAILURE);
}

/**
 * stack - Set the push mode to stack (LIFO)
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the 'stack' instruction in Monty bytecode
 *
 * This function sets the push mode to stack (Last-In, First-Out) in Monty.
 * It is typically called when encountering the 'stack' instruction in Monty
 * bytecode, indicating that subsequent 'push' instructions should push
 * elements onto the stack.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (data == NULL)
		_exit_prog(EXIT_FAILURE);

	data->push_mode = STACK_MODE;
}

/**
 * queue - Set the push mode to queue (FIFO)
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the 'queue' instruction in Monty bytecode
 *
 * This function sets the push mode to queue (First-In, First-Out) in Monty.
 * It is typically called when encountering the 'queue' instruction in Monty
 * bytecode, indicating that subsequent 'push' instructions should push
 * elements onto the queue.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (data == NULL)
		_exit_prog(EXIT_FAILURE);

	data->push_mode = QUEUE_MODE;
}
