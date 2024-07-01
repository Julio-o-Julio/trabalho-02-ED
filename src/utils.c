#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/utils.h"

int compara_nome(tcidade a, tcidade b) {
    return strcmp(a.nome, b.nome);
}

int compara_latitude(tcidade a, tcidade b) {
    if (a.latitude == b.latitude) return 0;
    if (a.latitude < b.latitude) return -1;
    return 1;
}

int compara_longitude(tcidade a, tcidade b) {
    if (a.longitude == b.longitude) return 0;
    if (a.longitude < b.longitude) return -1;
    return 1;
}

int compara_codigo_uf(tcidade a, tcidade b) {
    if (a.codigo_uf == b.codigo_uf) return 0;
    if (a.codigo_uf < b.codigo_uf) return -1;
    return 1;
}

int compara_ddd(tcidade a, tcidade b) {
    if (a.ddd == b.ddd) return 0;
    if (a.ddd < b.ddd) return -1;
    return 1;
}

int isValidLine(const char linha[])
{
    while (*linha != '\0')
    {
        if (*linha == '[' || *linha == ']' || *linha == '{' || *linha == '}')
        {
            return EXIT_FAILURE;
        }
        else if (*linha == '"')
        {
            return EXIT_SUCCESS;
        }
        linha++;
    }
    return EXIT_SUCCESS;
}

char *get_key_cidade(void *cidade)
{
    tcidade *c = (tcidade *)cidade;
    char *key = malloc(12);
    if (key == NULL)
    {
        printf("Erro ao alocar memória para a chave\n");
        exit(EXIT_FAILURE);
    }
    snprintf(key, 12, "%d", c->codigo_ibge);
    return key;
}
