/* Sistema */
#include <stdio.h>
/* Projeto */
#include "slib.h"

int main () {

    slib_put (3);
    slib_put (7);
    slib_put (9);
    slib_put (5);

    fprintf(stdout, "Valores: %d %d %d %d\n",
            slib_get(), slib_get(), slib_get(), slib_get());
    return 0;
}