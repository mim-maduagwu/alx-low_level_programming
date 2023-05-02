#include "lists.h"
size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Counts no of unique node
 * @head: ponter to head node
 * Return: 0 or no of nodes
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *shell, *speedy;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	shell = head->next;
	speedy = (head->next)->next;

	while (speedy)
	{
		if (shell == speedy)
		{
			shell = head;
			while (shell != speedy)
			{
				nodes++;
				shell = shell->next;
				speedy = speedy->next;
			}

			shell = shell->next;
			while (shell != speedy)
			{
				nodes++;
				shell = shell->next;
			}

			return (nodes);
		}

		shell = shell->next;
		speedy = (speedy->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - frees list safely
 * @h: pointer to head node
 * Return: Size of the list freed
 * Description: sets head to null
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t nodes, index;

	nodes = looped_listint_count(*h);

	if (nodes == 0)
	{
		for (; h != NULL && *h != NULL; nodes++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodes);
}


