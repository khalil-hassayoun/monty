#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 1 || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	pop_top(stack);
}

/**
 * pchar - print the char at the top of the stack, followed by a new line
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *temp;

	temp = (*stack);
	if (temp == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	i = temp->n;
	if (!(is_ascii(i)))
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	putchar(i);
	putchar('\n');
}

/**
 * pstr - print the string starting at the top of the stack, followed by a \n
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i;

	(void) line_number;
	temp = (*stack);
	while (temp != NULL && temp->n != 0 && is_ascii(temp->n))
	{
		i = temp->n;
		putchar(i);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl - rotate the stack up one, the top element shifts to the bottom
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int temp;

	(void) line_number;
	if (*stack == NULL)
		return;

	if (stack_len(*stack) > 1)
	{
		temp = pop_top(stack);
		add_node_end(stack, temp);
	}
}

/**
 * rotr - rotate the stack down one, the bottom element shift to the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node_a, *node_b;

	(void) line_number;
	node_a = (*stack);
	if (node_a == NULL)
		return;
	node_b = node_a;
	if (node_a->next == NULL)
		;
	else
	{
		while (node_b->next != NULL)
			node_b = node_b->next;
		node_b->prev->next = NULL;
		node_b->prev = NULL;
		node_b->next = node_a;
		node_a->prev = node_b;
		(*stack) = node_b;
	}
}
