#include "monty.h"

/**
 * get_opcode_func - check opcode and returns the correct function
 * @str: the opcode
 * 
 * Return: an opcode function, or NULL on failure
*/

instruction_func get_opcode_func(char *str)
{
    int i;

    instruction_t instruct[] = {
        {"push", _push},
        {"pall", _pall},
    };

    i = 0;
    while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
    {
        i++;
    }

    return (instruct[i].f);
}