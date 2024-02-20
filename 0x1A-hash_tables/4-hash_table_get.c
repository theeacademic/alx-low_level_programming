#include "hash_tables.h"
#include <string.h>
/**
* hash_table_get - retrieves a value associated with a key in a hash table
* @ht: the hash table you want to look into
* @key: the key you are looking for
*
* Return:value associated with the element, or NULL if key isn't present
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *node;
if (!ht || !key || strlen(key) == 0)
return (NULL);
index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];
while (node)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}
return (NULL);
}
