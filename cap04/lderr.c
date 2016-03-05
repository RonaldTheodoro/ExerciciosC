#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>


int main () {
    fprintf(stdout, "Resultado: %s\n", crypt ("teste", "a1"));
    return 0;
}