#include "lists.h"
/**
 * pop_listint - pops a node out
 * @head: list address
 * Return: head node
 */
int pop_listint(listint_t **head)
{
	int value = 0;
	listint_t *tmp;

	if (*head == NULL)
		return (value);
	tmp = *head;
	value = (*head)->n;
	*head = (*head)->next;

	free(tmp);

	return (value);
}
