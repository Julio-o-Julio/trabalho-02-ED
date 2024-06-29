#include <string.h>

#include "../include/utils.h"

int compara_nome(titem a, titem b)
{
    return strcmp(a.nome, b.nome);
}

int compara_latitude(titem a, titem b)
{
    return (a.latitude > b.latitude) - (a.latitude < b.latitude);
}

int compara_longitude(titem a, titem b)
{
    return (a.longitude > b.longitude) - (a.longitude < b.longitude);
}

int compara_codigo_uf(titem a, titem b)
{
    return a.codigo_uf - b.codigo_uf;
}

int compara_ddd(titem a, titem b)
{
    return a.ddd - b.ddd;
}
