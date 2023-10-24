#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely (handles loops) and counts nodes.
 * @h: Pointer to a pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *slow_ptr, *fast_ptr;
    size_t node_count = 0;

    slow_ptr = fast_ptr = *h;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        
        if (slow_ptr == fast_ptr)
        {
           
            slow_ptr = *h;
            while (slow_ptr != fast_ptr)
            {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }

            
            while (slow_ptr->next != fast_ptr)
                slow_ptr = slow_ptr->next;

            while (slow_ptr->next != fast_ptr)
            {
                listint_t *temp = slow_ptr->next;
                slow_ptr->next = temp->next;
                free(temp);
                node_count++;
            }

            
            free(slow_ptr->next);
            node_count++;

            *h = NULL;
            return node_count;
        }
    }

    
    while (*h != NULL)
    {
        listint_t *temp = *h;
        *h = (*h)->next;
	free(temp);
        node_count++;
    }

    return node_count;
}
