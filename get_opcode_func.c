#include "monty.h"

/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */

instruct_func get_opcode_func(char *str)
{
	int i;

	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};

	i = 0;
	while (instructions[i].f != NULL && strcmp(instructions[i].opcode, str) != 0)
	{
		i++;
	}

	return (instructions[i].f);
}
