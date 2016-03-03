#include <stdio.h>
#include <string.h>

#define CONFIG_FILE "sample.conf"

/* Define um tipo para ser utilizado como local de armazenamento da
 * configuração */
typedef struct {
    char language[10];
    char compiler[10];
    char parser[50];
    char editor[10];
    char osver[50];
    char name[128];
    char home[128];
    char uid[5];

} config_t;


/* Função para remove '\r' ou '\n' do final das linhas */
static char *strfix (char *str) {
    char *p;

    /* Anda por 'str' até encontrar '\r' ou '\n' e quando encontra troca por
     * '\0' */
    for (p = str; *p != '\0'; p++)
        if (*p == '\r' || *p == '\n') {
            *p = '\0';
            break;
        }
    return str;
}


int main(int argc, char const *argv[]) {
    int i;
    FILE *fp;
    char temp[128], *p;

    /* Local para armazenar e configuração do arquivo CONFIG_FILE */
    config_t conf;

    /* Estrutura genérica para definir as opções de configuração */
    typedef struct {
        char *optname;
        char buffer;
        int size;
    } parser_t;

    /* Todas as opções de configuração e o respectivo local de
     * armazenamento*/
    parser_t opts[] = {
        {"language", conf.language, sizeof (conf.language)},
        {"compiler", conf.compiler, sizeof (conf.compiler)},
        {"parser", conf.parser, sizeof (conf.parser)},
        {"editor", conf.editor, sizeof (conf.editor)},
        {"os version", conf.osver, sizeof (conf.osver)},
        {"programmer name", conf.name, sizeof (conf.name)},
        {"programmer home", conf.home, sizeof (conf.home)},
        {"programmer uid", conf.uid, sizeof (conf.uid)}
    };

    /* Tamanho real de opts */
    const int opts_size = sizeof (opts) / sizeof (opts[0]);

    /* Abre o arquivo de configuração */
    if ((fp = fopen (CONFIG_FILE, "r")) == NULL) {
        perror ("open");
        return 1;
    }

    /* Limpa o local de armazenamento */
    memset (&conf, 0, sizeof (conf));

    /* Loop até o fim do arquivo */
    while (!feof (fp)) {
        memset (temp, 0, sizeof (temp));

        /* Lê uma linha do arquivo o encerra o loop caso ocorra algum erro */
        if (fgets (temp, sizeof (temp), fp) == NULL) break;

        /* Volta ao começo do loop se encontrar linhas em branco ou
         * comentários... (ignora a linha) */
        p = temp;
        if (*p == '\r' || *p == '\n' || *p == '\t') continue;

        /* Procura o caracter '=' e caso não exista ignora a linha */
        while (*p != '=' && *p != '\0') p++;
        if (*p == '=') p++;
        else continue;

        /* Depois do caracter '=' pode ter espaço ou tab, então pula até
         * encontrar o conteudo da opção */
        while ((*p == ' ' || *p == '\t') && *p != '\0') p++;
        if (*p == '\0') continue;

        /* Compara os dados lidos com todasas possiveis opções... quando
         * encontra grava no local de armazenamento correto */

        for (i = 0; i < opts_size; i++)
            if (!strncmp (opts[i].optname, temp, strlen (opts[i].optname)))
                strncpy (opts[i].buffer, strfix (p), opts[i].size);
    }

    /* Fecha o arquivo de configuração */
    fclose (fp);

    /* Imprime todas as opções lidas */
    for (i = 0; i < opts_size; i++)
        if (*opts[i].buffer != '\0')
            fprintf(stdout, "%s = %s\n", opts[i].optname, opts[i].buffer);

    return 0;
}
