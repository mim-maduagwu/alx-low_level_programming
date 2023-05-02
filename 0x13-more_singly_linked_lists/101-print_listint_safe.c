#include "lists.h"

/**
 * count_node - node counter for uniques nodes
 * @head: pointer to head node
 * Return: no of unique nodes
 */
int count_node(const listint_t *head)
{
	int count = 0;
	const listint_t *shell, *speedy;

	shell = speedy = head;

	while (shell != NULL && speedy != NULL)
	{
		shell = shell->next;
		speedy = speedy->next->next;
		count++;

		if (shell == speedy)
		{
			shell = head;
			while (shell != speedy)
			{
				shell = shell->next;
				speedy = speedy->next;
				count++;
			}
			return (count);
		}
	}
	return (0);
}

/**
 * loop - find loop
 * @head: pointer to head node
 * Return: 0, 1
 */
int loop(const listint_t *head)
{
	const listint_t *shell, *speedy;

	shell = speedy = head;
	while (shell != NULL && speedy != NULL)
	{
		shell = shell->next;
		speedy = speedy->next->next;

		if (shell == speedy)
			return (1);
	}
	return (0);
}
/**
 * print_listint_safe - prints address lists
 * @head: pointer for header node
 * Return: no of nodes or 98
 */
size_t print_listint_safe(const listint_t *head)
{
	int count = 0;
	int found_loop;
	size_t num_nodes = 0;
	const listint_t *tmp;

	if (head == NULL)
		exit(98);

	found_loop = loop(head);

	if (found_loop == 1)
	{
		count = count_node(head);
		for (found_loop = 0; found_loop < count; found_loop++)
		{
			printf("[%p] %d\n", (void *)tmp, tmp->n);
			num_nodes += 1;
			tmp = tmp->next;
		}
	}
	else if (found_loop == 0)
	{
		tmp = head;
		while (tmp != NULL)
		{
			printf("[%p] %d\n", (void *)tmp, tmp->n);
			num_nodes += 1;
			tmp = tmp->next;
		}
	}
	return (num_nodes);
}

