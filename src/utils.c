#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/utils.h"
#include "../include/cidade.h"

int compara_nome(titem a, titem b)
{
    return strcmp(a.nomecidade.nome, b.nomecidade.nome);
}

int compara_latitude(titem a, titem b)
{
    if (a.latitudecidade.latitude < b.latitudecidade.latitude)
        return -1;
    else if (a.latitudecidade.latitude > b.latitudecidade.latitude)
        return 1;
    else
        return 0;
}

int compara_longitude(titem a, titem b)
{
    if (a.longitudecidade.longitude < b.longitudecidade.longitude)
        return -1;
    else if (a.longitudecidade.longitude > b.longitudecidade.longitude)
        return 1;
    else
        return 0;
}

int compara_codigo_uf(titem a, titem b)
{
    return a.codigoufcidade.codigo_uf - b.codigoufcidade.codigo_uf;
}

int compara_ddd(titem a, titem b)
{
    return a.dddcidade.ddd - b.dddcidade.ddd;
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
