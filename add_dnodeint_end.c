#include "monty.h"

/**
 * add_dnodeint_end - add node to end of list
 * @head: pointer to first node
 * @n: data inside node
 * Return: pointer to first node
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;
	return (new_node);
}
