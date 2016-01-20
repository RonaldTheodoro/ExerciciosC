#include <stdio.h>


int main () {
    int i;
    int str[] = {'s', 'o', 'u', ' ', 'u', 'm', ' ', 'v', 'e', 't', 'o', 'r'};

    for (i = 0; i < sizeof (str) / sizeof (int); i++)
        fprintf(stdout, "%p -> %c\n", &str[i], (char) str[i]);

}
