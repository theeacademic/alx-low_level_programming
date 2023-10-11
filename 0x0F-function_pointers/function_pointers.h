#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H
typedef void (*NamePrinter)(char *);

void print_name(char *name, NamePrinter f);
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));
#endif
