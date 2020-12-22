#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* function pointer typedef for readability and sanity */
typedef void (*function_type)(stack_t **stack, unsigned int line_number);

/** quick fix. stack type 0 is a normal LIFO/stack, stack type 1 FIFO/queue **/
extern int STACK_TYPE;

/* math_opcode */
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* opcode_1 */
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, char *value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/*opcode_2 */
void pop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* opcode_3 */
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void free_list(stack_t *head);
int is_ascii(int chr);

/* node_helper */
stack_t *add_node(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
int delete_node_at_index(stack_t **head, unsigned int index);
stack_t *get_node_at_index(stack_t *head, unsigned int index);

/* stack_helper */
int pop_top(stack_t **head);
size_t print_stack(const stack_t *h);
size_t stack_len(const stack_t *h);
size_t print_backwards_stack(const stack_t *h);
stack_t *add_result(stack_t **head, const int n);

/* errcheck */
void check_main(int argc);
int check_file(char *filename);
void *check_malloc(size_t size);
void bailout(stack_t *stack, char *buffer, int file);

/* input */
char *get_buffer(char *filename, int fd);
char **sanitize_input(char *line);
char *read_line(char *buffer);

/* main */
function_type get_func(char *s);
#endif /* MONTY_H */
