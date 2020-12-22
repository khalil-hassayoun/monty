#include "monty.h"

/**
 * nop - does not do anything
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * swap - swap the top two element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node_A, *node_B;
	int temp;

	if (stack_len(*stack) < 2 || *stack == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	node_A = *stack;
	node_B = node_A->next;
	temp = node_B->n;
	node_B->n = node_A->n;
	node_A->n = temp;
}

/**
 * pint - print the value at the top of the stack, followed by a newline
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 1 || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * push - push an element onto the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * @value: value passed from sanitized string in main
 *
 * Return: none
 */
void push(stack_t **stack, char *value, unsigned int line_number)
{
	int val;
	unsigned int i;

	if (value == NULL || value[0] == '\0')
	{
		printf("L%u: usage: push integer\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	i = 0;
	if (value[i] == '-')
		i++;
	for (i = i; i < strlen(value); i++)
	{
		if (isdigit(value[i]) == 0)
		{
			printf("L%u: usage: push integer\n", line_number);
			STACK_TYPE = -1;
			return;
		}
	}
	val = atoi(value);
	add_node(stack, val);
}

/**
 * pall - prints all the values on the stack, starting with the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 *
 * Return: none
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack != NULL)
		print_stack(*stack);
}
