#include "monty.h"

/**
 * read_file - reads a bytecode and run commands
 * @filename: pathname to the file
 * @stack: pointer the top of the stack
*/

void read_file(char *filename, stack_t **stack)
{
    char *buffer = NULL;
    char *line;
    size_t i = 0;
    int line_count = 1;
    instruction_func instruct_func;
    int check;
    int read;
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        error_exit(stack);
    }

    while ((read = getline(&buffer, &i, file)) != -1)
    {
        line = parse_line(buffer);

        if (line == NULL || line[0] == '#')
        {
            line_count++;
            continue;
        }

        instruct_func = get_opcode_func(line);
        if (instruct_func == NULL)
        {
            printf("L%d: unknown instruction %s\n", line_count, line);
            error_exit(stack);
        }

        instruct_func(stack, line_count);
        line_count++;
    }

    free(buffer);
    check = fclose(file);
    if (check == -1)
        exit(-1);
}