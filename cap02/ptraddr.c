#include <stdio.h>


int main () {
    char *p, str[] = "sou um vetor";

    p = str;

    while(*p != '\0') {
        fprintf(stdout, "%p -> %c\n", p, *p);
        p++;
    }

    return 0;
}