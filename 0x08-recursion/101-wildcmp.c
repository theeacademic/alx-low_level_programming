#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
int wildcmp(char *s1, char *s2);

int main() {
    char s1[] = "hello";
    char s2[] = "h*o";
    int result = wildcmp(s1, s2);
    
    if (result) {
        printf("The strings can be considered identical.\n");
    } else {
        printf("The strings are not identical.\n");
    }
    
    return 0;
}

