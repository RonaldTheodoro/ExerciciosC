#include <stdio.h>
#include <string.h>

struct pessoa {
    int idade;
    char nome[20];
    char desc[50];
};


static void my_print(struct pessoa *ptr);


int main() {
    struct pessoa bozo;

    memset(&bozo, 0, sizeof(bozo));
    bozo.idade = 31;

    snprintf(bozo.nome, sizeof(bozo.nome), "Bozo");
    snprintf(bozo.desc, sizeof(bozo.desc), "O palhaço de todos vocês!");

    my_print(&bozo);

    return 0;
}


static void my_print(struct pessoa *ptr) {
    fprintf(stdout, "Nome: %s\nIdade: %d\nDescrição: %s\n",
        ptr->nome, ptr->idade, ptr->desc);
}