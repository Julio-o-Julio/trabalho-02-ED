#ifndef __ENCADEADA__
#define __ENCADEADA__

#include "./cidade.h"

typedef int (*compara_)(tcidade a, tcidade b);

typedef struct _listaencadeada
{
    tcidade item;
    struct _listaencadeada *prox;
} tlistaencadeada;

tlistaencadeada *encadeada_procura(tlistaencadeada *head, tcidade item, compara_ cmp);
void encadeada_insere(tlistaencadeada **head, tcidade item);
void encadeada_remove(tlistaencadeada **head, tcidade item, compara_ cmp);
void encadeada_destroi(tlistaencadeada *head);

#endif
