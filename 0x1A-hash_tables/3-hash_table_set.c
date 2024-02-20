#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with the key.
 *
 * Return: Upon success, returns 1. Otherwise, returns 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    index = key_index((const unsigned char *)key, ht->size);
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return 0;
    }

    if (value != NULL)
    {
        new_node->value = strdup(value);
        if (new_node->value == NULL)
        {
            free(new_node->key);
            free(new_node);
            return 0;
        }
    }
    else
    {
        new_node->value = NULL;
    }

    temp = ht->array[index];
    ht->array[index] = new_node;
    new_node->next = temp;

    return 1;
}

