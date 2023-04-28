#include "lists.h"
/**
 * listint_len - len of list
 * @h: struct to iterate
 * Return: amount of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
