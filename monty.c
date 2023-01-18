#include "monty.h"

int stack_queue_flag = 0;

/**
 * main - program starting point
 * @ac: argument count
 * @av: argument vector
 * 
 * Return: 0
*/

int main(int ac, char **av)
{
    stack_t *stack = NULL;

    if (ac != 2)
    {
        printf("USEAGE: monty file\n");
        error_exit(&stack);
    }
    read_file(av[1], &stack);
    free_dlistint(stack);
    return (0);
}