/**
 * print_list - Prints the elements of a linked list of type list_t.
 * @h: A pointer to the head of the linked list.
 *
 * This function traverses the linked list starting from the given head node,
 * printing the string value and length of each node's str field.
 *
 * If the str field of a node is NULL, it prints "[0] (nil)" for that node.
 *
 * @h: A pointer to the head of the linked list to print.
 *
 * Return: The number of nodes in the linked list.
 */
#include <stdio.h>
#include "your_struct_definition.h"
#include "lists.h"
size_t print_list(const list_t *h)
{
size_t node_count = 0;
while (h != NULL)
{
if (h->str == NULL)
{
printf("[0] (nil)\n");
}
else
{
printf("[%u] %s\n", h->len, h->str);
}
h = h->next;
node_count++;
}
return (node_count);
}

