#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H
typedef void (*NamePrinter)(char *);

void print_name(char *name, NamePrinter f);

#endif
