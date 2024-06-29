#ifndef __AVL__
#define __AVL__

#include "./lista_encadeada.h"
#include "./cidade.h"

typedef tcidade titem;
typedef int (*compara_)(titem a, titem b);

typedef struct _node{
    titem item;
    struct _node *esq;
    struct _node *dir;
    struct _node *pai;
    struct _listaencadeada *listaencadeada;
    int h;
} tnode;

tnode* sucessor(tnode *node);
int avl_insere(tnode ** pparv, titem reg, compara_ cmp);
void avl_remove(tnode ** pparv, titem reg);
void avl_destroi(tnode * parv);

void _rd(tnode ** pparv);
void _re(tnode ** pparv);
void _avl_rebalancear(tnode ** pparv);

#endif
