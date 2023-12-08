#include <stddef.h>
/**
 * struct dlistint_s - Doubly linked list node structure
 * @n: Integer data stored in the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */
typedef struct dlistint_s
{
int n;
struct dlistint_s *prev;
struct dlistint_s *next;
}
dlistint_t;
/**
 * dlistint_len - Returns the number of elements in a doubly linked list
 * @h: Pointer to the head of the doubly linked list
 *
 * Return: The number of elements in the doubly linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t count = 0;
while (h != NULL)
{
count++;
h = h->next;
}
return (count);
}
