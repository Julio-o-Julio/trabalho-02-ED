#ifndef __AVL__
#define __AVL__

#include "./lista_encadeada.h"
#include "./cidade.h"

typedef int (*compara_)(tcidade a, tcidade b);

typedef struct _node
{
    tcidade item;
    struct _node *esq;
    struct _node *dir;
    struct _node *pai;
    struct _listaencadeada *listaencadeada;
    int h;
} tnode;

tnode *sucessor(tnode *node);
int avl_insere(tnode **pparv, tcidade reg, compara_ cmp);
void avl_remove(tnode **pparv, tcidade reg, compara_ cmp);
void avl_destroi(tnode *parv);

void _rd(tnode **pparv);
void _re(tnode **pparv);
void _avl_rebalancear(tnode **pparv);

#endif
