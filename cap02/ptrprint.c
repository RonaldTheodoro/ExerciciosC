#include <stdio.h>


int main (int argc, char const *argv[]) {
    char *ptr, tmp = 'A';

    fprintf(stdout, "ptr(%p) tem %d bytes.\n", &ptr, sizeof(ptr));
    fprintf(stdout, "tmp(%p) tem %d bytes.\n", &tmp, sizeof(tmp));

    ptr = &tmp;

    fprintf(stdout, "agora ptr(%p) aponta para tmp %c.\n", ptr, *ptr);
    fprintf(stdout, "mas o endereco de ptr(%p) e o mesmo.\n", &ptr);

    return 0;
}