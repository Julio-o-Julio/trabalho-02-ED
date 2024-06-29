#include <stdio.h>
#include <stdlib.h>
#include "../include/avl.h"
#include "../include/cidade.h"
#include "../include/lista_encadeada.h"

int max(int a, int b)
{
    return a > b ? a : b;
}

int altura(tnode *arv)
{
    int ret;
    if (arv == NULL)
    {
        ret = -1;
    }
    else
    {
        ret = arv->h;
    }
    return ret;
}

int avl_insere(tnode **parv, titem reg, compara_ cmp)
{
    int result;
    if (*parv == NULL)
    {
        *parv = (tnode *)malloc(sizeof(tnode));
        if (*parv == NULL) {
            return EXIT_FAILURE;
        }
        (*parv)->item = reg;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->pai = NULL;
        (*parv)->listaencadeada = NULL;
        (*parv)->h = 0;
        result = EXIT_SUCCESS;
    }
    else if (cmp(reg, (*parv)->item) < 0)
    {
        result = avl_insere(&(*parv)->esq, reg, cmp);
        if ((*parv)->esq != NULL) {
            (*parv)->esq->pai = *parv;
        }
    }
    else if (cmp(reg, (*parv)->item) > 0)
    {
        result = avl_insere(&(*parv)->dir, reg, cmp);
        if ((*parv)->dir != NULL) {
            (*parv)->dir->pai = *parv;
        }
    }
    else
    {
        encadeada_insere(&(*parv)->listaencadeada, reg.codigo_ibge);
        result = EXIT_SUCCESS;
    }
    (*parv)->h = max(altura((*parv)->esq), altura((*parv)->dir)) + 1;
    _avl_rebalancear(parv);

    return result;
}

void _rd(tnode **parv)
{
    tnode *y = *parv;
    tnode *x = y->esq;
    tnode *B = x->dir;

    x->dir = y;
    y->esq = B;
    *parv = x;

    y->h = max(altura(y->esq), altura(y->dir)) + 1;
    x->h = max(altura(x->esq), altura(x->dir)) + 1;

    x->pai = y->pai;
    y->pai = x;
    if (B)
    {
        B->pai = y;
    }
}

void _re(tnode **parv)
{
    tnode *x = *parv;
    tnode *y = x->dir;
    tnode *B = y->esq;

    y->esq = x;
    x->dir = B;
    *parv = y;

    x->h = max(altura(x->esq), altura(x->dir)) + 1;
    y->h = max(altura(y->esq), altura(y->dir)) + 1;

    y->pai = x->pai;
    x->pai = y;
    if (B)
    {
        B->pai = x;
    }
}

void _avl_rebalancear(tnode **parv)
{
    int fb;
    int fbf;
    tnode *filho;
    fb = altura((*parv)->esq) - altura((*parv)->dir);

    if (fb == -2)
    {
        filho = (*parv)->dir;
        fbf = altura(filho->esq) - altura(filho->dir);
        if (fbf <= 0)
        { /* Caso 1  --> ->*/
            _re(parv);
        }
        else
        { /* Caso 2  --> <-*/
            _rd(&(*parv)->dir);
            _re(parv);
        }
    }
    else if (fb == 2)
    {
        filho = (*parv)->esq;
        fbf = altura(filho->esq) - altura(filho->dir);
        if (fbf >= 0)
        { /* Caso 3  <-- <-*/
            _rd(parv);
        }
        else
        { /* Caso 4  <-- ->*/
            _re(&(*parv)->esq);
            _rd(parv);
        }
    }
}

tnode **percorre_esq(tnode **arv)
{
    tnode *aux = *arv;
    if (aux->esq == NULL)
    {
        return arv;
    }
    else
    {
        while (aux->esq->esq != NULL)
            aux = aux->esq;
        return &(aux->esq);
    }
}

void avl_remove(tnode **parv, titem reg, compara_ cmp)
{
    int cmp_result;
    tnode *aux;
    tnode **sucessor;
    if (*parv != NULL)
    {
        cmp_result = cmp((*parv)->item, reg);
        if (cmp_result > 0)
        { /* ir esquerda*/
            avl_remove(&((*parv)->esq), reg, cmp);
        }
        else if (cmp_result < 0)
        { /*ir direita*/
            avl_remove(&((*parv)->dir), reg, cmp);
        }
        else
        { /* ACHOU  */
            if ((*parv)->esq == NULL && (*parv)->dir == NULL)
            { /* no folha */
                free(*parv);
                *parv = NULL;
            }
            else if ((*parv)->esq == NULL || (*parv)->dir == NULL)
            { /* tem um filho*/
                aux = *parv;
                if ((*parv)->esq == NULL)
                {
                    *parv = (*parv)->dir;
                }
                else
                {
                    *parv = (*parv)->esq;
                }
                free(aux);
            }
            else
            { /* tem dois filhos */
                sucessor = percorre_esq(&(*parv)->dir);
                (*parv)->item = (*sucessor)->item;
                avl_remove(&(*parv)->dir, (*sucessor)->item, cmp);
            }
        }
        if (*parv != NULL)
        {
            (*parv)->h = max(altura((*parv)->esq), altura((*parv)->dir)) + 1;
            _avl_rebalancear(parv);
        }
    }
}

void avl_destroi(tnode *parv)
{
    if (parv != NULL)
    {
        avl_destroi(parv->esq);
        avl_destroi(parv->dir);
        free(parv);
    }
}

tnode *minimo(tnode *node)
{
    while (node->esq != NULL)
    {
        node = node->esq;
    }
    return node;
}

tnode *sucessor(tnode *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->dir != NULL)
    {
        return minimo(node->dir);
    }

    tnode *p = node->pai;
    while (p != NULL && node == p->dir)
    {
        node = p;
        p = p->pai;
    }
    return p;
}
