#ifndef _ERROR_H_
#define _ERROR_H_

#include "monty.h"

#define EMONTY_FILE 300
#define EOPEN_FILE 301
#define EUNKOWN_INSTRUCTION 302
#define EMALLOC_FAILED 303
#define EPUSH_INTEGER 304

/**
 * struct error_handler_s - error handler for error messages
 * @code: error code
 * @handler: function that write error code message to stderr
 */
typedef struct error_handler_s
{
	int code;
	int (*handler)(va_list args);
} error_handler_t;

/* print_error.c */
void print_error(int error_code, ...);

/* errors.c */
int monty_file_error(va_list args);
int cannot_open_file_error(va_list args);
int unknown_instruction_error(va_list args);
int malloc_error(va_list args);
int push_integer_error(va_list args);

#endif /* _ERROR_H_ */
