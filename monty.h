#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "error.h"

/**
 * enum PUSH_MOD_ENUM - enumeration defines two constants representing
 * push modes for a Monty interpreter program. These modes determine
 * whether elements should be pushed onto a stack or a queue.
 *
 * @STACK_MODE: (Value: 0): Represents the stack mode, where elements are
 * pushed onto the stack. In stack mode, the last element pushed is the
 * first to be popped (Last In, First Out - LIFO).
 *
 * @QUEUE_MODE: (Value: 1): Represents the queue mode, where elements
 * are pushed into the queue. In queue mode, the first element pushed
 * is the first to be dequeued (First In, First Out - FIFO).
 */
typedef enum PUSH_MOD_ENUM
{
	STACK_MODE,
	QUEUE_MODE
} PUSH_MODE;

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
 * @mode: integer flag indicating push mode
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
	PUSH_MODE mode;
} program_data_t;

extern program_data_t *data;

/* file_interpreter.c */
void interpret_file(FILE *file);

/* execute_opcode.c */
void execute_opcode(opcode_info_t *info);

/*utils.c*/
bool is_integer(const char *str);
stack_t *create_stack_t_node(int n);

/* opcode_operations_1.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **head, int n);
void push_queue(stack_t **head, int n);

/* opcode_operations_2.c */
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);

/* opcode_operations_3.c */
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/* opcode_operations_4.c */
void rotr(stack_t **stack, unsigned int line_number);

/* free.c */
void free_stack_t(stack_t *head);
void free_program_data_t(program_data_t *data);

/* _exit_prog.c */
void _exit_prog(int code);

#endif /* MONTY_H_ */
