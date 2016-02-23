#include <stdio.h>
#include <stdlib.h>


static void my_finish ();
static void my_cleanup ();


int main (int argc, char const *argv[]) {
    atexit (my_finish);
    atexit (my_cleanup);
    return 0;
}


static void my_finish () {
    fprintf(stdout, "Finalizando os dispositivos\n");
}


static void my_cleanup () {
    fprintf(stdout, "Fechando arquivos de configuracao\n");
}