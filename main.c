#include "monty.h"

int STACK_TYPE;
/**
 * main - main function for monty interpreter
 * takes in a single argument, a file (hopefully) containing monty script
 *
 * @argc: argument count
 * @argv: 2d array containing command line arguments
 * Return: exits on EXIT_SUCCESS or EXIT_FAILURE accordingly
 */
int main(int argc, char **argv)
{
	int file, estatus; unsigned int line_number;
	char *buffer, *line; char **sanitized;
	function_type func; stack_t *stack;

	STACK_TYPE = 0; stack = NULL; check_main(argc);
	file = check_file(argv[1]); buffer = get_buffer(argv[1], file);
	line_number = 0; estatus = EXIT_SUCCESS;
	while ((line = read_line(buffer)))
	{
		line_number++;
		sanitized = sanitize_input(line);
		if (sanitized[0] != NULL)
		{
			if (sanitized[0][0] != '#' && strcmp(sanitized[0], "nop") != 0)
			{
				if (strcmp(sanitized[0], "push") == 0)
					push(&stack, sanitized[1], line_number);
				else
				{
					func = get_func(sanitized[0]);
					if (func == NULL)
					{
						printf("L%u: unknown instruction %s\n",
						       line_number, sanitized[0]);
						STACK_TYPE = -1;
					}
					else
						func(&stack, line_number);
				}
				if (STACK_TYPE == -1)
				{
					estatus = EXIT_FAILURE;
					free(sanitized);
					break;
				}
			}
		}
		free(sanitized);
	}
	bailout(stack, buffer, file); exit(estatus);
}

/**
 * get_func - takes in a string, returns appropriate function pointer
 * uses a table of instruction_t structs and matches the opcode to the string
 *
 * @s: string that should contain opcode
 * Return: returns the function, or NULL on failure
 */
function_type get_func(char *s)
{
	instruction_t inst[] = {
		{"sub", sub}, {"div", div_op},
		{"nop", nop}, {"add", add},
		{"swap", swap}, {"pint", pint},
		{"pall", pall}, {"pop", pop},
		{"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr},
		{"stack", stack}, {"queue", queue},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (i < 16)
	{
		if (strcmp((inst[i]).opcode, s) == 0)
			return ((inst[i]).f);
		i++;
	}
	return (NULL);
}
