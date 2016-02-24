#include <stdio.h>
#include <stdlib.h>

/* numero máximo de callbacks permitidos */
#define MAX_CALLBACKS 8


/* matriz de ponteiros com os callbacks */
static void *callbacks[MAX_CALLBACKS];
static int callbacks_pos = 0;


/* implementação de my_atexit() */
static int my_atexit(void (*func)(void)) {
    /* caso haja posição disponível na matriz, guarda o ponteiro */
    if(callbacks_pos < MAX_CALLBACKS) {
        callbacks[callbacks_pos++] = func;
        return 0;
    }
    /* caso já existam MAX_CALLBACKS-1 funções agendadas, retorna erro */
    return -1;
}


/* implementação de my_exit() */
static void my_exit(int status) {
    void (*func)(void);

    /* executa todas as funções agendadas, de trás pra frente */
    while(callbacks_pos != -1)
        if((func = callbacks[callbacks_pos--]) != NULL)
            func();

    /* termina o programa */
    exit(status);
}

/* funções de teste... */
static void func0(void) { fprintf(stdout, "função 0...\n"); }
static void func1(void) { fprintf(stdout, "função 1...\n"); }
static void func2(void) { fprintf(stdout, "função 2...\n"); }
static void func3(void) { fprintf(stdout, "função 3...\n"); }
static void func4(void) { fprintf(stdout, "função 4...\n"); }
static void func5(void) { fprintf(stdout, "função 5...\n"); }
static void func6(void) { fprintf(stdout, "função 6...\n"); }
static void func7(void) { fprintf(stdout, "função 7...\n"); }
static void func8(void) { fprintf(stdout, "função 8...\n"); }
static void func9(void) { fprintf(stdout, "função 9...\n"); }


int main() {
    my_atexit(func0);
    my_atexit(func1);
    my_atexit(func2);
    my_atexit(func3);
    my_atexit(func4);
    my_atexit(func5);
    my_atexit(func6);
    my_atexit(func7);
    my_atexit(func8);
    my_atexit(func9);

    my_exit(0);

    /* nunca será executado! */
    return 0;
}