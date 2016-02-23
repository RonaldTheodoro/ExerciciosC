#include <stdio.h>
#include <stdlib.h>

/* Numero maximo de callbacks */
#define MAX_CALLBACKS 8

/* Matriz de ponteiros com os callbacks */
static void *callbacks[MAX_CALLBACKS];
static int callbacks_pos = 0;


/* Implementação de my_atexit */
static int my_atexit (void (*func) (void));
/* Implementação de my_exit */
static void my_exit (int status);
/* Funções de teste */
static void func0 (void);
static void func1 (void);
static void func2 (void);
static void func3 (void);
static void func4 (void);
static void func5 (void);
static void func6 (void);
static void func7 (void);
static void func8 (void);
static void func9 (void);


int main () {
    my_atexit (func0);
    my_atexit (func1);
    my_atexit (func2);
    my_atexit (func3);
    my_atexit (func4);
    my_atexit (func5);
    my_atexit (func6);
    my_atexit (func7);
    my_atexit (func8);
    my_atexit (func9);

    my_exit(0);
    return 0;
}

static int my_atexit (void (*func) (void)) {
    /* Caso haja posição disponivel na matriz, guarda o ponteiro */
    if (callbacks_pos < MAX_CALLBACKS) {
        callbacks[callbacks_pos++] = func;
        return 0;
    }

    /* Caso já existam MAX_CALLBACKS - 1 funções agendadas, retorna erro */
    return -1;
}


static void my_exit (int status) {
    void (*func) (void);

    /* Executa todas as funções agendadas, de três pra frente */
    while (callbacks_pos != -1)
        if ((func = callbacks[callbacks_pos--]) != NULL)
            func();

    /* Finaliza o programa */
    exit (status);
}


static void func0 (void) { fprintf(stdout, "Função0 ...\n"); }
static void func1 (void) { fprintf(stdout, "Função1 ...\n"); }
static void func2 (void) { fprintf(stdout, "Função2 ...\n"); }
static void func3 (void) { fprintf(stdout, "Função3 ...\n"); }
static void func4 (void) { fprintf(stdout, "Função4 ...\n"); }
static void func5 (void) { fprintf(stdout, "Função5 ...\n"); }
static void func6 (void) { fprintf(stdout, "Função6 ...\n"); }
static void func7 (void) { fprintf(stdout, "Função7 ...\n"); }
static void func8 (void) { fprintf(stdout, "Função8 ...\n"); }
static void func9 (void) { fprintf(stdout, "Função9 ...\n"); }
