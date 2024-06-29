#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/utils.h"
#include "../include/cidade.h"

int compara_nome(titem a, titem b)
{
    tnomecidade *ca = (tnomecidade *)a;
    tnomecidade *cb = (tnomecidade *)b;
    return strcmp(ca->nome, cb->nome);
}

int compara_latitude(titem a, titem b)
{
    tlatitudecidade *ca = (tlatitudecidade *)a;
    tlatitudecidade *cb = (tlatitudecidade *)b;
    if (ca->latitude < cb->latitude)
        return -1;
    if (ca->latitude > cb->latitude)
        return 1;
    return 0;
}

int compara_longitude(titem a, titem b)
{
    tlongitudecidade *ca = (tlongitudecidade *)a;
    tlongitudecidade *cb = (tlongitudecidade *)b;
    if (ca->longitude < cb->longitude)
        return -1;
    if (ca->longitude > cb->longitude)
        return 1;
    return 0;
}

int compara_codigo_uf(titem a, titem b)
{
    tcodigoufdecidade *ca = (tcodigoufdecidade *)a;
    tcodigoufdecidade *cb = (tcodigoufdecidade *)b;
    if (ca->codigo_uf < cb->codigo_uf)
        return -1;
    if (ca->codigo_uf > cb->codigo_uf)
        return 1;
    return 0;
}

int compara_ddd(titem a, titem b)
{
    tdddcidade *ca = (tdddcidade *)a;
    tdddcidade *cb = (tdddcidade *)b;
    if (ca->ddd < cb->ddd)
        return -1;
    if (ca->ddd > cb->ddd)
        return 1;
    return 0;
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
