#ifndef __ENCADEADA__
#define __ENCADEADA__

#include "./avl.h"

typedef void *titem;
typedef int (*compara_)(titem a, titem b);

typedef struct _listaencadeada
{
    titem item;
    struct _listaencadeada *prox;
} tlistaencadeada;

tlistaencadeada *encadeada_procura(tlistaencadeada *head, titem item, compara_ cmp);
void encadeada_insere(tlistaencadeada **head, titem item);
void encadeada_remove(tlistaencadeada **head, titem item, compara_ cmp);
void encadeada_destroi(tlistaencadeada *head);

#endif
