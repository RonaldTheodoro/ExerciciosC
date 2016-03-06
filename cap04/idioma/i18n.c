#include <stdio.h>
#include <locale.h>
#include <libintl.h>


/* Chama a gettext() */
#define _(str) gettext(str)

int main () {
    /* Informa que o dominio 'i18n' pode ser encontrado em ./locale */
    bindtextdomain ("i18n", "./locale");

    /* Informa que gettext() deve utilizar o dominio 'i18n' */
    textdomain ("i18n");

    /* definir o locale como "" siginifica utilizar o valor das variaveis de
     * ambiente */
    setlocale (LC_ALL, "");
    setlocale (LC_MESSAGES, "");

    /* Imprime a mensagem utilizando a macro _(str) que é a chamada a
     * gettext(str) */
    fprintf(stdout, _("Hello World!\n"));
    return 0;
}