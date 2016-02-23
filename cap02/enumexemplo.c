#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    typedef struct {
        int s1;
        double s2;
    } numero;

    numero n1;

    n1.s1 = 10;
    n1.s2 = 15.00;

    printf ("int: %d, double: %.2f", n1.s1, n1.s2);

    return 0;
}