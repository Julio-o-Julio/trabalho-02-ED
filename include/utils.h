#ifndef __UTILS__
#define __UTILS__

#include "./lista_encadeada.h"
#include "./cidade.h"

int compara_nome(tcidade a, tcidade b);
int compara_latitude(tcidade a, tcidade b);
int compara_longitude(tcidade a, tcidade b);
int compara_codigo_uf(tcidade a, tcidade b);
int compara_ddd(tcidade a, tcidade b);

int isValidLine(const char linha[]);
char *get_key_cidade(void *cidade);

void imprime_resultados(tlistaencadeada *resultados);

#endif
