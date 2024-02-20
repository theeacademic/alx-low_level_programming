#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

typedef struct hash_table_s
{
    unsigned long int size;
    void **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);

#endif /* HASH_TABLES_H */

