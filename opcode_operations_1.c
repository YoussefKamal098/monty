#include "monty.h"

/**
 * push - Push an element onto the stack or queue
 * @stack: A double pointer to the head of the stack (or queue)
 * @line_number: Line number indicating the source line in the Monty file
 *
 * This function pushes an element onto the stack or queue based on the current
 * push mode (stack or queue). It takes the stack pointer and the line number
 * indicating the source line in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *first_opcode_token;

	if (stack == NULL || data == NULL || data->opcode_info == NULL)
		_exit_prog(EXIT_FAILURE);

	first_opcode_token = data->opcode_info->tokens[0];

	if (first_opcode_token == NULL)
	{
		print_error(E_PUSH_INTEGER, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if (is_integer(first_opcode_token) == 0)
	{
		print_error(E_PUSH_INTEGER, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	n = atoi(first_opcode_token);

	if (data->mode == STACK_MODE)
		push_stack(stack, n);
	else
		push_queue(stack, n);
}

/**
 * pall - Print the elements of a stack
 * @stack: A double pointer to the head of the stack.
 * @line_number: Line number (not used in this function)
 *
 * This function prints the elements of a
 * stack to the standard output (stdout).
 * It traverses the stack starting from the
 * head and prints each element's value followed by a newline.
 */

void pall(stack_t **stack, unsigned int line_number)
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

/**
 * pint - Print the top element of the stack
 * @stack: A double pointer to the head of the stack.
 * @line_number: Line number of the 'pint' instruction in Monty bytecode
 *
 * This function prints the top element of the stack. If the stack is empty,
 * it prints an error message and exits the program.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int top;

	if (stack == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*stack == NULL)
	{
		print_error(E_STACK_EMPTY, "pint", line_number);
		_exit_prog(EXIT_FAILURE);
	}

	top = (*stack)->n;
	printf("%d\n", top);
}

/**
 * push_stack - Push a new node onto the stack
 * @head: A double pointer to the head of the stack
 * @n: The integer value to be added to the new node.
 *
 * This function pushes a new node onto the stack. If the stack is empty,
 * the new node becomes the head of the stack. If the stack is not empty,
 * the new node is inserted at the top of the stack, and its next and
 * previous pointers are updated accordingly.
 */
void push_stack(stack_t **head, int n)
{
	stack_t *tmp;
	stack_t *new_node = create_stack_t_node(n);

	if (new_node == NULL)
		print_error(E_MALLOC_FAILED);

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
 * push_queue - Push a new node onto the queue
 * @head: A double pointer to the front of the queue
 * @n: The integer value to be added to the new node.
 *
 * This function pushes a new node onto the queue. If the queue is empty,
 * the new node becomes the head of the queue. If the queue is not empty,
 * the new node is inserted at the end of the queue, and its next and
 * previous pointers are updated accordingly.
 */
void push_queue(stack_t **head, int n)
{
	stack_t *tmp;
	stack_t *new_node = create_stack_t_node(n);

	if (new_node == NULL)
		print_error(E_MALLOC_FAILED);

	if (head == NULL || new_node == NULL)
		_exit_prog(EXIT_FAILURE);

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
}
