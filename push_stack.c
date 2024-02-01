#include "monty.h"

stack_t *create_stack_node(int n);
void push_stack(stack_t **head, stack_t *new_node);
void push_queue(stack_t **head, stack_t *new_node);

/**
 * push - Push an element onto the stack or queue
 * @stack: Pointer to the head of the stack (or queue)
 * @line_number: Line number indicating the source line in the Monty file
 *
 * This function pushes an element onto the stack or queue based on the current
 * push mode (stack or queue). It takes the stack pointer and the line number
 * indicating the source line in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *first_opcode_token;

	if (stack == NULL || data == NULL || data->opcode_info == NULL)
		_exit_prog(EXIT_FAILURE);

	first_opcode_token = data->opcode_info->tokens[0];

	if (first_opcode_token == NULL)
	{
		print_error(EPUSH_INTEGER, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	if (is_integer(first_opcode_token) == 0)
	{
		print_error(EPUSH_INTEGER, line_number);
		_exit_prog(EXIT_FAILURE);
	}

	node = create_stack_node(atoi(first_opcode_token));

	if (data->push_mode == STACK_MODE)
		push_stack(stack, node);
	else
		push_queue(stack, node);
}

/**
 * create_stack_node - Create a new node for the stack
 * @n: Integer value to be stored in the new node
 *
 * This function creates a new node for the stack, initializes its values,
 * and returns a pointer to the created node. If memory allocation fails, it
 * prints an error message and exits the program.
 *
 * Return: Pointer to the newly created stack node.
 */
stack_t *create_stack_node(int n)
{
	stack_t *node;

	node = (stack_t *)malloc(sizeof(stack_t));

	if (node == NULL)
	{
		print_error(EMALLOC_FAILED);
		_exit_prog(EXIT_FAILURE);
	}

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

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
 * push_queue - Push a new node onto the queue
 * @head: Pointer to the head of the queue
 * @new_node: Pointer to the new node to be pushed onto the queue
 *
 * This function pushes a new node onto the queue. If the queue is empty,
 * the new node becomes the head of the queue. If the queue is not empty,
 * the new node is inserted at the end of the queue, and its next and
 * previous pointers are updated accordingly.
 */
void push_queue(stack_t **head, stack_t *new_node)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
}
