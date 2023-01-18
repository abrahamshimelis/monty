#include "monty.h"

/**
 * error_exit - frees the stack and exits due to err
 * @stack: pointer to the head of stack
*/

void error_exit(stack_t **stack)
{
    if (*stack)
        free_dlistint(*stack);
    exit(EXIT_FAILURE);
}