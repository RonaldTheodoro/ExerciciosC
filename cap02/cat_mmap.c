#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>


static void cat_mmap (char *filename) {
    int fd;
    struct stat st;
    char *mem = NULL;

    /* Abre o arquivo */
    if ((fd = open(filename, O_RDONLY)) == -1) {
        perror ("open");
        return ;
    }

    /* Obtem informações do arquivo */
    if (fstat (fd, &st) == -1) {
        perror ("fstat");
        close (fd);
        return ;
    }

    /* Mapeia */
    mem = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mem == MAP_FAILED) {
        perror ("mmap");
        close (fd);
        return ;
    } else
        close (fd);

    /* Imprime no terminal */
    fprintf (stdout, "-- %s (%d bytes) --\n", filename, (int) st.st_size);
    fwrite (mem, sizeof (char), st.st_size, stdout);

    /* Desaloca a memoria */
    munmap (mem, st.st_size);
}


int main (int argc, char **argv) {
    char **fn;

    if (argc < 2) {
        fprintf (stdout, "Use: %s arquivo[s]...\n", *argv);
        return 1;
    } else
        fn = ++argv;

    while (--argc)
        cat_mmap (*fn++);

    return 0;
}