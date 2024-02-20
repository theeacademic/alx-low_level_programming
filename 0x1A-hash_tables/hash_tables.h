#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

typedef struct hash_table_s
{
    unsigned long int size;
    void **array;
} hash_table_t;
typedef struct hash_node {
    char *key;
    char *value;
    struct hash_node *next;
} hash_node_t;
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
#endif /* HASH_TABLES_H */

