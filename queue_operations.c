#include "monty.h"

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
