#include <stdio.h>
#include <string.h>

/* Utilizado para guardar valores inteiros */
static int slib_stack[3], slib_stack_pos = 0;
const int slib_stack_size = sizeof (slib_stack) / sizeof (slib_stack[0]);

/* Inicializa a biblioteca */
void slib_init (void) {
    /* Limpa a área da memoria */
    memset (slib_stack, 0, sizeof (slib_stack));
}

/* Adciona um valor ao stack */
int slib_put (int in) {
    if (slib_stack_pos == slib_stack_size) return -1;
    else
        slib_stack[slib_stack_pos++] = in;

    return in;
}

/* Retira o valor do stack */
int slib_get () {
    if (!slib_stack_pos) return -1;

    return slib_stack[--slib_stack_pos];
}

/* Finaliza a biblioteca */
void slib_quit (void) {
    /* Limpa a área de memoria */
    slib_init ();
}