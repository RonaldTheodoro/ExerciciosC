#include <stdio.h>
#include <string.h>


static int my_strlen(char *str);


int main() {
    char temp[128];
    memset(temp, 0, sizeof(temp));
    snprintf(temp, sizeof(temp), "sou um vetor");
    fprintf(stdout, "string \"%s\" tem %d bytes.\n", temp, my_strlen(temp));
    return 0;
}


static int my_strlen(char *str) {
    int count = 0;
    while(*str++ != '\0')
        count++;

    return count;
}
