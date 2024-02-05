#include "monty.h"

void tokenize_line(char *buffer, opcode_info_t *info);

/**
 * interpret_file - Interpret Monty bytecode from a file
 * @file: Pointer to a FILE struct representing the Monty bytecode file
 *
 * This function is responsible for interpreting Monty bytecode from a file.
 * It reads each line from the file, tokenize the line, and executes the
 * corresponding opcode. The interpretation process continues until the end
 * of the file is reached.
 */

void interpret_file(FILE *file)
{
	char *buffer = NULL;
	size_t read_bytes = 0;
	opcode_info_t opcode_info = {NULL, {NULL}, 1};

	if (file == NULL || data == NULL)
		_exit_prog(EXIT_FAILURE);

	data->opcode_info = &opcode_info;

	while (getline(&buffer, &read_bytes, file) != EOF)
	{
		if (buffer == NULL)
		{
			print_error(E_MALLOC_FAILED);
			_exit_prog(EXIT_FAILURE);
		}

		data->buffer = buffer;

		tokenize_line(buffer, &opcode_info);
		if (opcode_info.code)
			execute_opcode(&opcode_info);

		opcode_info.line++;
	}

	free_program_data_t(data);
}

/**
 * tokenize_line - Tokenize a line of Monty bytecode into opcode information
 * @buffer: Pointer to a character buffer containing a line of Monty bytecode
 * @info: Pointer to an opcode_info_t struct to store opcode information
 *
 * This function is responsible for tokenizing a line of Monty bytecode,
 * extracting the opcode and associated tokens,
 * and storing the information in an opcode_info_t
 * struct. It uses the strtok function with a specified delimiter to
 * split the line.
 */

void tokenize_line(char *buffer, opcode_info_t *info)
{
	const char *delim = " \r\t\n";

	if (buffer == NULL || info == NULL)
		_exit_prog(EXIT_FAILURE);

	info->code = strtok(buffer, delim);
	if (info->code == NULL)
		return;

	info->tokens[0] = strtok(NULL, delim);
}
