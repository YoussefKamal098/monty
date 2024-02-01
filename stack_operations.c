#include "monty.h"

/**
 * push_stack - Push a new node onto the stack
 * @head: Pointer to the head of the stack
 * @new_node: Pointer to the new node to be pushed onto the stack
 *
 * This function pushes a new node onto the stack. If the stack is empty,
 * the new node becomes the head of the stack. If the stack is not empty,
 * the new node is inserted at the top of the stack, and its next and
 * previous pointers are updated accordingly.
 */
void push_stack(stack_t **head, stack_t *new_node)
{
	stack_t *tmp;

	if (head == NULL || new_node == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	tmp = *head;
	*head = new_node;
	(*head)->next = tmp;
	tmp->prev = *head;
}

/**
 * print_stack - Print the elements of a stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number (not used in this function)
 *
 * This function prints the elements of a
 * stack to the standard output (stdout).
 * It traverses the stack starting from the
 * head and prints each element's value followed by a newline.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
