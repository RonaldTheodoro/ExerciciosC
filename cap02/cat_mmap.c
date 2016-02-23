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
}
