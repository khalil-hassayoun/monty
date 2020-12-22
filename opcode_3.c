#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	STACK_TYPE = 0;
}


/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	STACK_TYPE = 1;
}

/**
 * free_list - free a stack_t type list
 * @head: pointer to first node of list
 *
 * Return: void
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * is_ascii - checks if char is valid ASCII
 * @chr: char to check
 * Return: 1 on ascii, 0 on non-ascii
 */
int is_ascii(int chr)
{
	if (chr < 0 || chr > 127)
		return (0);
	return (1);
}
