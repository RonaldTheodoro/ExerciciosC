#include <errno.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>


/* Aplica 'regex' em 'filename' */
static void match (const regex_t *regex, const char *filename);

int main(int argc, char const **argv){
    regex_t reg;
    int r, c = argc - 2;
    char err[128], *regex, **files;

    if (argc < 2) {
        fprintf (stderr, "use: %s eregex [file1, file2...]\n", *argv);
        return 1;
    }

    regex = argv[1];
    files = &argv[2];

    /* Compila a espressão regular */

    return 0;
}


static void match (const regex t *regex, const char *filename) {

}