#include <stdio.h>
#include "lists.h"
void before_main(void) __attribute__((constructor));

void before_main(void) {
    printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}

int main(void) {
    printf("Inside the main function.\n");
    return 0;
}
