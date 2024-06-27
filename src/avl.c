#include <stdio.h>
#include <stdlib.h>
#include "./avl.h"

int max(int a, int b){
	return a > b ? a : b;
}

int altura(tnode *arv){
	if (arv == NULL)
		return -1;
	else
		return arv->h; 
}

void _rd(tnode ** parv){
	tnode * y = *parv;
	tnode * x = *y->esq;
	tnode * A = *x->esq;
	tnode * B = *x->dir;
	tnode * C = *y->dir;

	y->esq = B;
	x->dir = y;
	*parv = x;

	y->h = max(altura(B), altura(C)) + 1;
	x->h = max(altura(A), altura(y)) + 1;
}

void _re(tnode ** parv){
	tnode * x = *parv;
	tnode * y = x->dir;
	tnode * A = x->esq;
	tnode * B = y->esq;
	tnode * C = y->dir;

	x->dir = B;
	y->esq = x;
	*parv = y;
	
	x->h = max(altura(A), altura(B)) + 1;
	y->h = max(altura(x), altura(C)) + 1;
}

void _avl_rebalancear(tnode ** parv){
	int fb;
	int fbf;
	tnode * filho;
	fb = altura((*parv)->esq) - altura((*parv)->dir);

	if (fb == -2){
		filho = (*parv)->dir;
		fbf = altura(filho->esq) - altura(filho->dir);
		if (fbf <= 0) {
			_re(parv);
		} else {
			_rd(&(*parv)->dir);
			_re(parv);
		}
	} else if (fb == 2) {
		filho = (*parv)->esq;
		fbf = altura((*parv)->esq) - altura((*parv)->dir);
		if (fbf >= 0){
			_rd(parv);
		} else {
			_re(&(*parv)->esq);
			_rd(parv);
		}
	}
}

void insere(tnode ** parv, titem item){
	if (*parv == NULL){
		*parv = (tnode *) malloc(sizeof(tnode));
		(*parv)->item = item;
		(*parv)->esq = NULL;
		(*parv)->dir = NULL;
		(*parv)->h = 0;
	} else if (((*parv)->item - item) > 0){
		insere(&(*parv)->esq, item);
	} else {
		insere(&(*parv)->dir, item);
	}

	(*parv)->h = max(altura((*parv)->esq), altura((*parv)->dir)) + 1;
	_avl_rebalancear(parv);
}

tnode ** percorre_esq(tnode ** parv){
	tnode * aux = *parv;
	if (aux->esq == NULL){
		return parv;
	} else {
		while(aux->esq->esq != NULL) {
			aux = aux->esq;
		return &(aux->esq);
}

void avl_remove(tnode ** parv, titem reg) {
	
}

void avl_destroi(tnode *parv){
	if (parv != NULL) {
		avl_destroi(parv->esq);
		avl_destroi(parv->dir);
		free(parv);
	}
}
