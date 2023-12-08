#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_dlistint - Print all elements of a doubly linked list
 * @h: Pointer to the head of the doubly linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
const dlistint_t *current = h;
size_t node_count = 0;
size_t count;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
node_count++;
}
count = node_count;
return (count);
}

