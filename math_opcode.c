#include "monty.h"

/**
 * sub - subtract the top element of @stack from the second top element
 * @stack: pointer to head pointer of the stack
 * @line_number: line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int minus, total;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	minus = pop_top(stack);
	total = pop_top(stack);
	add_result(stack, total - minus);
}

/**
 * div_op - divide the second element of the @stack with the top element
 * @stack: pointer to head pointer of the stack
 * @line_number: line number
 *
 * Return: void
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int quotient, divisor;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	divisor = pop_top(stack);
	quotient = pop_top(stack);
	quotient /= divisor;
	add_result(stack, quotient);

}

/**
 * mul - multiply the second element of the @stack with the top element
 * @stack: pointer to head pointer of the stack with the top element
 * @line_number: line number
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	product = pop_top(stack);
	product *= pop_top(stack);
	add_result(stack, product);
}

/**
 * add - add the first and second elements of the @stack
 * @stack: pointer to head pointer of the stack with the top element
 * @line_number: line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	sum = pop_top(stack);
	sum += pop_top(stack);
	add_result(stack, sum);
}
/**
 * mod - compute the rest of the division of the second element of the @stack
 * with the top element
 * @stack: pointer to head pointer of the stack with the top element
 * @line_number: line number
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int modulo, divisor;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		STACK_TYPE = -1;
		return;
	}
	divisor = pop_top(stack);
	modulo = pop_top(stack);
	modulo %= divisor;
	add_result(stack, modulo);
}
