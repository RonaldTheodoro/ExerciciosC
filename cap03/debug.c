#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* Função com lista  de argumentos variaveis */
static void debug (const char *fmt, ...) {
    va_list ap;
    
    if (getenv ("DEBUG")) {
        va_start (ap, fmt);
        fprintf (stdout, "Debug: ");
        vfprintf (stdout, fmt, ap);
        va_end (ap);
    }
}


int main () {
    int x = 1, y = 2;
    
    fprintf (stdout, "Realizando procedimento X...\n");
    debug ("Calculando resultado de x + y: %d\n", x + y);
    
    fprintf (stdout, "Realizando procedimento Y...\n");
    debug ("Calculando resultado de x + y: %d\n", x - y);
    
    return 0;
}
