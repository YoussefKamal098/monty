#include "monty.h"

program_data_t *data = NULL;

/**
 * main - Entry point
 * @argc: Number of arguments that passed to the program
 * @argv: Arguments that passed to the program
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	const char *file_path;
	program_data_t program_data = {NULL, NULL, NULL, NULL, STACK_MODE};

	if (argc != 2)
	{
		print_error(E_MONTY_FILE);
		exit(EXIT_FAILURE);
	}

	file_path = argv[1];
	file = fopen(file_path, "r");

	if (file == NULL)
	{
		print_error(E_OPEN_FILE, file_path);
		exit(EXIT_FAILURE);
	}

	data = &program_data;
	data->file = file;

	interpret_file(file);
	return (0);
}
