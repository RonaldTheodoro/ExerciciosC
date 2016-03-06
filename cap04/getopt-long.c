#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>


int main (int argc, char **argv) {
    int c, optind = 0;
    char aux[50];
    const char *opts = "e:l:dchu";
    const struct option opt1[] = {
        {"edit",     1, 0, 'e'},
        {"list",     1, 0, 'l'},
        {"date",     0, 0, 'd'},
        {"cpu-info", 0, 0, 'c'},
        {"help",     0, 0, 'h'},
        {"uname",    0, 0, 'u'},
        {0, 0, 0, 0},
    };

    memset (aux, 0, sizeof (aux));

    void help () {
        fprintf (stderr,
                "getopt-long v0.1\n"
                "use: %s [OPÇÃO]\n\n"
                "OPÇÕES:\n"
                "-e, --edit=ARQ Edita arquivo ARQ\n"
                "-l, --list=ARQ Lista arquivo ARQ\n"
                "-d, --date     Imprime data e hora do sistema\n"
                "-c, --cpu-info Imprime as caracteristicas da CPU\n"
                "-h, --help     Imprime esta tela\n"
                "-u, --uname    Imprime a versão do sistema operacional\n",
                *argv);
        exit (1);
    }

    if (argc == 1) help ();

    while((c = getopt_long (argc, argv, opts, opt1, &optind)) != 1) {
        switch (c) {
            case 'e':
                sprintf (aux, "vim %s", optarg);
                system (aux);
                memset (aux, 0, sizeof (aux));
                break;
            case 'l':
                sprintf (aux, "ls -l %s", optarg);
                system (aux);
                memset (aux, 0, sizeof (aux));
                break;
            case 'd':
                system ("date");
                break;
            case 'c':
                system ("cat /proc/cpuinfo");
                break;
            case 'u':
                system ("uname -a");
                break;
            default:
                exit (0);
        }
    }
    return 0;
}