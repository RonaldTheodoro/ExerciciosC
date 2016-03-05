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
    if ((r = regecomp (&reg, regex, REG_EXTENDED | REG_NEWLINE | REG_NOSUB))) {
        memset (err, 0, sizeof (err));
        regerror (r, &reg, err, sizeof (err));
        regfree (&reg);
        fprintf(stderr, "regex error: %s\n", err);
        return 1;
    }

    if (c)
        /* Procura no[s] arquivo[s] */
        while (c--)
            match (&reg, *files++);
    else
        /* Procura no stdin */
        match (&reg, NULL);

    /* Desaloca a memoria da expressão alocada */
    regfree(&reg);

    return 0;
}


static void match (const regex_t *regex, const char *filename) {
    int line = 0;
    char temp[1024];
    FILE *fp = filename ? fopen (filename, "r") : stdin;

    /* Caso não seja posivel abrir o arquivo... */
    if (!fp) {
        fprintf(stderr, "%s: %s\n", filename, strerror (errno));
        return ;
    }

    while (!feof (fp)) {
        memset (temp, 0, sizeof (temp));
        if (fgets (temp, sizeof (temp), fp) == NULL) break;

        line++;

        /* Executa a expressão regular na linha */
        if (regexec (regex, temp, 0, 0, 0) == REG_NOMATCH)
            continue;
        else
            fprintf(stdout, "%s(%d): %s",
                    filename ? filename : "-stdin-", line, temp);
    }

    if (filename) fclose (fp);
}