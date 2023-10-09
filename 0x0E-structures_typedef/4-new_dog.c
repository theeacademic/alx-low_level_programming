#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"
/**
 * new_dog - Creates a new dog and returns a pointer to it.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: Pointer to the new dog, or NULL if memory allocation fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog_ptr;
char *name_copy, *owner_copy;
new_dog_ptr = malloc(sizeof(dog_t));
if (new_dog_ptr == NULL)
return (NULL);
name_copy = malloc(strlen(name) + 1);
owner_copy = malloc(strlen(owner) + 1);
if (name_copy == NULL || owner_copy == NULL)
{
free(new_dog_ptr);
free(name_copy);
free(owner_copy);
return (NULL);
}
strcpy(name_copy, name);
strcpy(owner_copy, owner);
new_dog_ptr->name = name_copy;
new_dog_ptr->age = age;
new_dog_ptr->owner = owner_copy;
return (new_dog_ptr);
}
