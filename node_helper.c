#include "monty.h"

/**
 * add_node - add a new node at the beginning of a stack_t list
 * @head: pointer to head of stack
 * @n: value of new node
 *
 * Return: the address of new element, or NULL if fail
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	if (STACK_TYPE == 1)
		return (add_node_end(head, n));
	new = check_malloc(sizeof(*new));
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (*head);
}

/**
 * add_result - adds to the beginning, regardless of stack type
 * @head: pointer to head of stack
 * @n: value of new node
 *
 * Return: the address of new element, or NULL if fail
 */
stack_t *add_result(stack_t **head, const int n)
{
	stack_t *new;

	new = check_malloc(sizeof(*new));
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (*head);
}

/**
 * add_node_end - add a new node to end of stack_t type list
 * @head: pointer to a pointer to list
 * @n: value of new node
 *
 * Return: address of the new element, or NULL if fail
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *root, *new;

	new = check_malloc(sizeof(*new));
	root = *head;
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (root->next)
		root = root->next;
	new->prev = root;
	root->next = new;
	return (new);
}

/**
 * delete_node_at_index - delete a specific node in a stack_t type list
 * @head: pointer to a head of the stack
 * @index: index of the node to delete, starting at 0
 *
 * Return: 1 if success, -1 if fail
 */
int delete_node_at_index(stack_t **head, unsigned int index)
{
	stack_t *node, *target;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	i = 0;
	node = *head;
	while (node && i < index)
	{
		node = node->next;
		i++;
	}
	if (i < index)
		return (-1);
	if (i == 0 && node->next)
	{
		target = node;
		node = node->next;
		node->prev = NULL;
		*head = node;
		free(target);
		return (1);
	}
	else if (i > 0)
	{
		target = node;
		node = node->prev;
		node->next = target->next;
		free(target);
	}
	else
	{
		*head = node->next;
		free(node);
	}
	return (1);
}

/**
 * get_node_at_index - locate the nth node of a stack_t type list
 * @head: pointer to first node in list
 * @index: index of the node to locate
 *
 * Return: the node at location @index
 */
stack_t *get_node_at_index(stack_t *head, unsigned int index)
{
	stack_t *target;
	unsigned int i;

	target = head;
	if (head == NULL)
		return (NULL);
	if (target->next)
	{
		i = 0;
		while (i < index)
		{
			target = target->next;
			i++;
		}
		return (target);
	}
	return (NULL);
}
