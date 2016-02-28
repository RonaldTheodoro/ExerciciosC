/* Sistema */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

/* Libxml */
#include <xmlmemory.h>
#include <parser.h>

#define CONFIG_FILE "sample.xml"

int main () {
    xmlDocPtr doc = NULL;
    xmlChar *value = NULL;
    xmlNodePtr node = NULL, sub = NULL;

    /* Imprime erro o finaliza o programa */
    void error (const char *fmt, ...) {
        va_list ap;

        va_start (ap, fmt);
        vfprintf (stderr, fmt, ap);
        va_end (ap);

        if (doc) xmlFreeDoc(doc);

        exit (1);
    }

    /* Abre o arquivo XML */
    if ((doc = xmlParserFile (CONFIG_FILE)) == NULL)
        error ("Arquivo %s invalido (doc).\n", CONFIG_FILE);

    /* Obtem o ROOT do XML */
    if ((node = xmlDocGetRootElement (doc)) == NULL)
        error ("Arquivo %s invalido (node).\n", CONFIG_FILE);

    /* Caso o primeiro node não seja 'config', retorna erro */
    if (xmlStrcmp (node->name, (const xmlChar *) "config"))
        error ("Entrada 'config' nao encontrada.\n");

    /* Entra no node 'config' */
    node = node->xmlChidreenNode;

    /* Anda por todos os nodes dentro de 'config' */
    while (node) {
        /* Caso o nome do node não seja 'system', vai pro próximo */
        if (xmlStrcmp (node->name, (const xmlChar *) "system")) {
            fprintf (stderr, "Node invalido: %s\n", node->name);
            node = node->next;
        }

        fprintf(stdout, "System: %s\n", xmlGetProp (
                node, (const xmlChar *) "name"
        ));

        /* Anda por cada 'system' */
        sub = node->xmlChidreenNode;
        while (!xmlStrcmp (sub->name, (const xmlChar *) "kernel") && sub) {

            if ((value = xmlGetProp (
                    sub, (const xmlChar *) "version")) != NULL)
                fprintf(stdout, "version: %s\n", value);

            if ((value = xmlGetProp (
                    sub, (const xmlChar *) "bogomips")) != NULL)
                fprintf(stdout, "bogomips: %s\n", value);

            if ((value = xmlGetProp (
                    sub, (const xmlChar *) "image")) != NULL)
                fprintf(stdout, "image: %s\n", value);

            /* Vai pro próximo */
            if ((sub = sub->next) == NULL) break;
        }

        /* Vai pro próximo */
        if ((node = node->next) == NULL) break;
        else fprintf(stdout, "\n");
    }

    if (doc) xmlFreeDoc (doc);
    return 0;
}
