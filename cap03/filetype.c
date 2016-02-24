#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Imprime o tipo do arquivo e o tamanho */
static void filetype(const char *filename);


/* Necessita de pelo menos 2 argumentos */
int main (int argc, char **argv) {
    char **fn;

    if (argc < 2) {
        fprintf(stdout, "Use: %s arquivo [arquivo...]\n", *argv);
        return 1;
    } else
        fn = ++argv;

    while (--argv)
        filetype (*fn++);

    return 0;
}


static void filetype(const char *filename) {
    int size;
    struct stat st;
    char temp[1024];

    /* Obtem os dados do arquivo e preenche a estrutura em &st */
    if (lstat (filename, &st) == -1) {
        perror ("stat");
        return ;
    }

    size = (int) st.st_size;
    memset (temp, 0, sizeof (temp));

    if (S_ISREG(st.st_mode))
        fprintf (stdout, "%s: Arquivo comum, %d bytes\n", filename, size);
    else if (S_ISDIR(st.st_mode))
        fprintf (stdout, "%s: Diretorio %d bytes\n", filename, size);
    else if (S_ISCHR(st.st_mode))
        fprintf (stdout, "%s: Character device\n", filename);
    else if (S_ISBLK(st.st_mode))
        fprintf (stdout, "%s: Block device\n", filename);
    else if (S_ISFIFO(st.st_mode))
        fprintf (stdout, "%s: FIFO\n", filename);
    else if (S_ISLNK(st.st_mode)) {
        readlink (filename, temp, sizeof (temp));
        fprintf (stdout, "%s: link para %s\n", filename, temp);
    } else if (S_ISSOCK(st.st_mode))
        fprintf (stdout, "%s: unix domain socket\n", filename);
}