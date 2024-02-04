#include "monty.h"

/**
 * free_stack_t - Free memory allocated for a stack (doubly linked list)
 * @head: Pointer to the head of the stack (doubly linked list)
 *
 * This function is responsible for freeing the memory allocated for a stack,
 * represented as a doubly linked list. It takes the head of the stack as a
 * parameter and iteratively traverses the stack, freeing each node until the
 * end is reached.
 */
void free_stack_t(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * free_program_data - Free memory allocated for Monty program data
 * @data: Pointer to a program_data_t struct containing program-specific data
 *
 * This function is responsible for freeing the memory allocated for Monty
 * program data. It takes a pointer to a program_data_t struct as a parameter
 * and releases resources associated with the stack, buffer, and file.
 */
void free_program_data(program_data_t *data)
{
	if (data == NULL)
		return;

	if (data->stack_head)
		free_stack_t(data->stack_head);
	if (data->buffer)
		free(data->buffer);
	if (data->file && fclose(data->file))
		perror("Error closing file");
}
