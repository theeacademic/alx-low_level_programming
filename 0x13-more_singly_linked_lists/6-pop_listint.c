#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes head node of listint_t list and returns its data.
 * @head: Pointer to a pointer to the head of the list
 *
 * Return: Data (n) of the deleted head node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
int data = 0;
listint_t *temp;

if (*head != NULL)
{
temp = *head;
data = temp->n;
*head = temp->next;
free(temp);
}
return (data);
}
