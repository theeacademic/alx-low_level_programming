#include "hash_tables.h"
#include <stdio.h>

/**
* hash_table_print - prints a hash table
* @ht: the hash table
*
* If ht is NULL, don’t print anything
*/
void hash_table_print(const hash_table_t *ht)
{
unsigned long int i;
hash_node_t *node;
char *sep = "";
if (!ht)
return;
printf("{");
for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node)
{
printf("%s'%s': '%s'", sep, node->key, node->value);
sep = ", ";
node = node->next;
}
}
printf("}\n");
}

