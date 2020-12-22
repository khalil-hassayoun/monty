#include "monty.h"

/**
 * check_main - handles error checking for the main function
 * no needed return value
 *
 * @argc: argument count from main func
 */
void check_main(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file - handles file error checking on open
 *
 * @filename: argv[1], filename we're opening
 * Return: Returns the fd we open if successful
 */
int check_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}


/**
 * check_malloc - malloc with built-in error checking
 *
 * @size: size to malloc
 * Return: Returns malloc return, or exits with proper message
 */
void *check_malloc(size_t size)
{
	void *pntr;

	pntr = malloc(size);
	if (pntr == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (pntr);
}

/**
 * bailout - function to try to make a clean exit
 * @stack: head of stack
 * @buffer: buffer
 * @file: fd to close out
 */
void bailout(stack_t *stack, char *buffer, int file)
{
	free_list(stack);
	free(buffer);
	close(file);
}
