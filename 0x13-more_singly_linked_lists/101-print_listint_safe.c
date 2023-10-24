#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints all elements of a listint_t list (handles loops safely).
 * @head: Pointer to the head of the list
 *
 * Return: Number of nodes in the list (or -1 if a loop is detected)
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow_ptr, *fast_ptr;
size_t node_count = 0;
slow_ptr = fast_ptr = head;
while (slow_ptr && fast_ptr && fast_ptr->next)
{
slow_ptr = slow_ptr->next;
fast_ptr = fast_ptr->next->next;
printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
node_count++;
if (slow_ptr == fast_ptr)
{
printf("Loop detected!\n");
return (-1);
}
}
return (node_count);
}
