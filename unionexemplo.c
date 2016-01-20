#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    union valores {
        int vi;
        double vd;
    };

    union valores v1;

    v1.vd = 15.00;
    v1.vi = 10;

    printf ("Inteiro: %d, Double: %f", v1.vi, v1.vd);

    return 0;
}