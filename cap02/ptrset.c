#include <stdio.h>


int main () {
    char *p, str[] = "sou um vetor";

    p = str;
    p += 5;

    fprintf (stdout, "%c, %c\n", *p, p[2]);

    return 0;
}