#include <stdio.h>


static int soma (int x, int y);


int main () {
    int (*somaptr) (int x, int y);
    somaptr = soma;
    fprintf(stdout, "Resultado: %d\n", somaptr(8, 5));
    fprintf(stdout, "Resultado: %d\n", somaptr(100, 5));
    fprintf(stdout, "Resultado: %d\n", somaptr(8, 250));
    return 0;
}


static int soma (int x, int y) {
    return x + y;
}