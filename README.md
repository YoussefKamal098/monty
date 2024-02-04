## Monty Interpreter

The Monty Interpreter is a program written in C that interprets Monty bytecode files. Monty is a scripting language that utilizes a unique stack data structure. This interpreter supports various stack and queue operations specified in the bytecode file.

## Table of Contents

- [Monty Interpreter](#monty-interpreter)
- [Table of Contents](#table-of-contents)
- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Opcode Operations](#opcode-operations)
- [Error Handling](#error-handling)
- [Build and Run](#build-and-run)
- [Contributions](#contributions)
- [Known Bugs](#known-bugs)
- [Show your Support](#show-your-support)
- [Authors ©](#authors-)


## Introduction

This project comprises a Monty bytecode interpreter implemented in C. The interpreter processes Monty bytecode files, executes stack and queue operations, and provides error handling for various scenarios.

## Project Structure

The project is organized into several source files:

- `monty.h`: Header file containing structure definitions and function prototypes.
- `error.h`: Header file with error code definitions and error handling functions.
- `file_interpreter.c`: File containing the function to interpret Monty bytecode from a file.
- `execute_opcode.c`: File with the function to execute Monty opcodes based on opcode information.
- `utils.c`: File containing utility functions like checking if a string represents a valid integer.
- `opcode_operations_*.c`: Files with functions implementing various stack and queue operations.
- `free.c`: File containing functions to free allocated memory.
- `_exit_prog.c`: File with the function to exit the program.

## Usage

To use the Monty Interpreter, create a Monty bytecode file with the desired stack and queue operations. Then, run the interpreter with the following command:

```bash
./monty <filename>
```
Replace `<filename>` with the path to your Monty bytecode file.

## Opcode Operations

The interpreter supports various opcode operations, including:

- `push`: Push an element onto the stack or queue.
- `pall`: Print all elements of the stack or queue.
- `pint`: Print the top element of the stack.
- `pop`: Remove the top element of the stack.
- `swap`: Swap the top two elements of the stack.
- `add`, `sub`, `mul`, `div`, `mod`: Arithmetic operations on the stack.
- `pchar`: Print the character value at the top of the stack.
- `pstr`: Print the string starting from the top of the stack.
- `rotl`, `rotr`: Rotate the stack to the left or right.

Refer to the source files for more details on each opcode operation.

## Error Handling

The interpreter provides error handling for various situations, such as:

- Monty file not found.
- Unable to open the Monty file.
- Unknown instruction in the Monty file.
- Memory allocation failure.
- Invalid integer for the `push` operation.
- Stack underflow or stack too short.
- Division by zero.
- Out-of-range values.

The error codes and corresponding error messages are defined in the `error.h` file.

## Build and Run
To build the Monty Interpreter, compile the source files using your preferred C compiler. For example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu99 *.c -o monty
``` 

Then, run the compiled executable as mentioned in the [Usage](#usage) section.

## Contributions

Contributions to the Monty Interpreter are welcome! Fork the repository, make your changes, and submit a pull request. Please follow the existing code style and conventions.

## Known Bugs
Currently no known bugs. 🤝 Feel free to check the [issues page](../../issues/).

## Show your Support

Give me a ⭐️ if you like this project!

## Authors &copy;
- Youssef Samuel Kamal - [YoussefKamal098](https://github.com/YoussefKamal098)