#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "error.h"

#define UNUSED __attribute((unused))

#define STACK_MODE 0
#define QUEUE_MODE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct opcode_info_s - representation of opcode information
 * @code: opcode string
 * @tokens: array of token strings (size 1 for simplicity)
 * @line: line number in the Monty bytecode file
 *
 * Description: Node structure for storing information about Monty opcodes.
 * Each node represents a specific opcode and contains relevant data.
 */
typedef struct opcode_info_s
{
	char *code;
	char *tokens[1];
	size_t line;
} opcode_info_t;

/**
 * struct program_data_s - program data structure
 * @opcode_info: pointer to an opcode_info_t struct
 * @file: pointer to a FILE struct (representing the Monty bytecode file)
 * @buffer: pointer to a character buffer for reading file contents
 * @stack_head: pointer to the head of a stack (doubly linked list)
 * @push_mode: integer flag indicating push mode
 * (e.g., 0 for stack, 1 for queue)
 *
 * Description: Structure for storing data related to
 * the Monty interpreter program. It includes information about the
 * Monty bytecode file, the opcode information,
 * the stack, and the push mode.
 */
typedef struct program_data_s
{
	opcode_info_t *opcode_info;
	FILE *file;
	char *buffer;
	stack_t *stack_head;
	int push_mode;
} program_data_t;

extern program_data_t *data;

/* file_interpreter.c */
void interpret_file(const FILE *file);

/* execute_opcode.c */
void execute_opcode(opcode_info_t *info);

/*utils.c*/
bool is_integer(char *str);

/* push.c */
void push(stack_t **stack, unsigned int line_number);

/* stack_operations.c */
void print_stack(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **head, stack_t *new_node);

/* queue_operations.c */
void push_queue(stack_t **head, stack_t *new_node);

/* free.c */
void free_stack(stack_t *head);
void free_program_data(program_data_t *data);

/* _exit_prog.c */
void _exit_prog(int code);

#endif /* _MONTY_H_ */
