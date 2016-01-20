#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char str[] = "sou um vetor";

    for (i = 0; i < strlen(str); i++)
        fprintf (stdout, "%p -> %c\n", &str[i], str[i]);

    return 0;
}