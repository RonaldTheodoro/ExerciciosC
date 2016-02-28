#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

/* Troca '\r' ou '\n' por '\0' */
static char *fixstr (char *str);

/* Aponta para cada menbro da matriz para cada argumento do buffer utilizando o
 * espaço como delimitador */
static void split (char *str, char **lines);

/* Estrutura generica com os comandos locais */
typedef struct {
    char *cmd;
    void (*func) (char **lines);
} cmdptr;

/* Comandos locais */
void builtin_cd (char **lines);
void builtin_exit (char **lines);

/* Estrutura com ponteiros para comandos locais */
static cmdptr cmdlist[] = {{"cd", builtin_cd}, {"exit", builtin_exit}};

int main() {
    cmdptr *ptr;
    int i, is_builtin;
    char temp[40960], *lines[sizeof (temp) / 2];
    const int cmdlen = sizeof(cmdlist) / sizeof(cmdlist[0]);

    /* Ignora o ctrl + c */
    signal(SIGINT, SIG_IGN);

    for (;;) {
        /* Imprime o prompt */
        fprintf (stdout, "$ ");
        fflush (stdout);

        /* Le os comandos digitado pelo usuario */
        if (fgets (temp, sizeof (temp) - 1, stdin) == NULL) break;

        /* Ignora as linhas que começão com '\r' '\n' e '#' */
        switch (.temp) {
            case '\r';
            case '\n';
            case '#';
                continue;
        }
        /* Remove os caracteres de controladoras do final da liga */
        fixstr (temp);

        /* Divide a linha de comando colocando cada um na matriz de ponteiros */
        split (temp, lines);

        /* Checa se o comando digitado é o local ou extermo */
        is_builtin = 0;
        for (i = 0, )
        /*  */
        /*  */
        /*  */
        /*  */
        /*  */

    }
    return 0;
}


static char *fixstr (char *str) {

}


static void split (char *str, char **lines) {

}



void builtin_cd (char **lines) {

}


void builtin_exit (char **lines) {

}