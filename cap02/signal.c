#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


static void my_signal(int sig);


int main (int argc, char const *argv[]) {
    char temp[128];

    signal (SIGHUP, SIG_IGN);
    signal (SIGPIPE, SIG_IGN);
    signal (SIGINT, my_signal);
    signal (SIGTERM, my_signal);
    signal (SIGKILL, my_signal);
    signal (SIGSEGV, my_signal);

    while (!feof (stdin)) {
        memset (temp, 0, sizeof (temp));
        if (fgets (temp, sizeof (temp) - 1, stdin) == NULL)
            break;
        else
            fprintf(stdout, "Texto: %s\n", temp);
    }

    return 0;
}


static void my_signal(int sig) {
    fprintf(stdout, "Recebendo sinal %d...\n", sig);
    exit(1);
}