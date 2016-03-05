#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>


/* Procura a expresão 'regex' em 'str' e retorna o resultado */
static char *match (char *str, char *regex);

int main() {
    char temp[128], *p;

    /* Cria string para primeiro teste */
    memset (temp, 0, sizeof (temp));
    snprintf (temp, sizeof (temp), "opcao = valor");

    /* Executa primeiro teste */
    p = match (temp, "^opcao = (.*)$");
    fprintf (stdout, "p = %s\n", p);

    /* Cria string para segundo teste */
    memset (temp, 0, sizeof (temp));
    snprintf (temp, sizeof (temp), "nome: bozo");

    /* Executa segundo teste */
    p = match (temp, "^nome: (.*)$");
    fprintf (stdout, "p = %s\n", p);

    return 0;
}


static char *match (char *str, char *regex) {
    int r;
    char err[128], *p;
    const int nmatch = 2;

    regex_t reg;
    regmatch_t result[nmatch];

    memset (err, 0, sizeof (err));
    memset (&result, 0, sizeof (result));

    /* Compila a expressão 'regex' */
    if ((r = regcomp (&reg, regex, REG_EXTENDED))) {
        regerror (r, &reg, err, sizeof (err));
        regfree (&reg);
        fprintf(stderr, "regcomp: %s\n", err);
        return NULL;
    }

    /* Executa a expressão em 'temp' */
    if (regexec (&reg, str, nmatch, result, 0) == REG_NOMATCH) {
        regfree (&reg);
        return NULL;
    }

    /* Aponta 'p' para o offset de incio da substring */
    p = str + result[1].rm_so;

    /* Coloca '\0' no final da substring */
    p[result[1].rm_eo] = '\0';

    /* Retorna 'p' contendo apenas a substring*/
    return p;
}
