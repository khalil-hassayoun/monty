#include "monty.h"

/**
 * stack_len - returns length of the stack
 *
 * @h: head of stack dlist
 * Return: Returns number of nodes in stack dlist
 */
size_t stack_len(const stack_t *h)
{
        unsigned int i;

        i = 0;
        while (h != NULL)
        {
                h = h->next;
                i++;
        }
        return (i);
}


/**
 * print_stack - prints out the stack
 *
 * @h: dlistint_t head
 * Return: Returns number of elements in dlistin_t
 */
size_t print_stack(const stack_t *h)
{
        int i;

        i = 0;
        while (h != NULL)
        {
                printf("%d\n", h->n);
                h = h->next;
                i++;
        }
        return (i);
}

/**
 * pop_top - removes the first element of the stack and returns the value
 *
 * @head: head of the stack
 * Return: returns the value at the top of the stack, or -1 on failure
 */
int pop_top(stack_t **head)
{
        int retval;

        if (*head == NULL)
                return (-1);
        retval = (*head)->n;
        delete_node_at_index(head, 0);

        return (retval);
}
