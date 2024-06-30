#ifndef __UTILS__
#define __UTILS__

#include "../include/titem.h"

int compara_nome(titem a, titem b);
int compara_latitude(titem a, titem b);
int compara_longitude(titem a, titem b);
int compara_codigo_uf(titem a, titem b);
int compara_ddd(titem a, titem b);
int isValidLine(const char linha[]);
char *get_key_cidade(void *cidade);

#endif
