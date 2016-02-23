#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
    struct pessoa {
        char nome[30];
        int idade;
        char telefone[15];
    };

    struct pessoa p1;


    printf ("Digite o seu nome: ");
    setbuf(stdin, NULL);
    gets (p1.nome);

    printf ("DIgite sua idade: ");
    scanf ("%d", &p1.idade);

    printf ("Digite o seu telefone: ");
    setbuf(stdin, NULL);
    gets (p1.telefone);

    printf ("Nome: %s, Idade: %d, Telefone: %s\n",
        p1.nome, p1.idade, p1.telefone);

    return 0;
}