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
    char temp[4096], *lines[sizeof (temp) / 2];
    const int cmdlen = sizeof(cmdlist) / sizeof(cmdlist[0]);

    /* Ignora o ctrl + c */
    signal(SIGINT, SIG_IGN);
    while (1) {
        /* Imprime o prompt */
        fprintf (stdout, "$ ");
        fflush (stdout);

        /* Le os comandos digitado pelo usuario */
        if (fgets (temp, sizeof (temp) - 1, stdin) == NULL) break;

        /* Ignora as linhas que começão com '\r' '\n' e '#' */
        switch (*temp) {
            case '\r':
            case '\n':
            case '#':
                continue;
        }
        /* Remove os caracteres de controladoras do final da liga */
        fixstr (temp);

        /* Divide a linha de comando colocando cada um na matriz de ponteiros */
        split (temp, lines);

        /* Checa se o comando digitado é o local ou extermo */
        is_builtin = 0;
        for (i = 0, ptr = cmdlist; i < cmdlen; i++, ptr++) {
            if (!strcmp (*lines, ptr->cmd)) {
                ptr->func (&lines[1]);
                is_builtin = 1;
            }
        }

        /* Se for comando interno, volta ao começo do loop */
        if (is_builtin) continue;

        /* Execute o comando externo */
        switch (fork ()) {
            case -1:
                perror ("fork");
                exit (1);
            case 0:
                execvp (*lines, lines);
                perror ("exec");
                _exit (1);
            default:
                wait (NULL);
        }
    }

    return 0;
}


static char *fixstr (char *str) {
    char *p;
    for (p = str; *p != '\0'; p++)
        if (*p == '\r' || *p == '\n') {
            *p = '\0';
            break;
        }

    return str;
}


static void split (char *str, char **lines) {
    while (*str != '\0') {
        while (*str == ' ' && *str != '\0') *str++ = '\0';
        *lines++ = str;
        while (*str != ' ' && *str != '\0') str++;
    }

    *lines = NULL;
}


void builtin_cd (char **lines) {
    if (chdir (*lines) == -1)
        perror ("chdir");
}


void builtin_exit (char **lines) {
    fprintf(stdout, "oooops!\n");
    exit (0);
}