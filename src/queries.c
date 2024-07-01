#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/avl.h"
#include "../include/cidade.h"
#include "../include/queries.h"

void busca_codigos_ibge_avl(tnode *parv, char *campo, compara_ cmp, char *comparador, void *item, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        printf("Erro ao buscar %s Arvore vazia!", (char *) item);
        return;
    }

    int resultComparador;

    if (strcmp(comparador, "==") == 0) {
        resultComparador = 0;
    } else if (strcmp(comparador, "<") == 0) {
        resultComparador = -1;
    } else if (strcmp(comparador, ">") == 0) {
        resultComparador = 1;
    } else {
        printf("Digite um comparador valido (==, <, >)");
        return;
    }

    if (strcmp(campo, "latitude") == 0)
    {
        double valor = *(double *) item;
        busca_codigos_ibge_avl_latitude(parv, cmp, resultComparador, valor, resultados);
    } else if (strcmp(campo, "longitude") == 0)
    {
        double valor = *(double *) item;
        busca_codigos_ibge_avl_longitude(parv, cmp, resultComparador, valor, resultados);
    } else if (strcmp(campo, "ddd") == 0)
    {
        int valor = *(int *) item;
        busca_codigos_ibge_avl_ddd(parv, cmp, resultComparador, valor, resultados);
    } else if (strcmp(campo, "codigo_uf") == 0)
    {
        int valor = *(int *) item;
        busca_codigos_ibge_avl_codigo_uf(parv, cmp, resultComparador, valor, resultados);
    } else if (strcmp(campo, "nome") == 0)
    {
        char *valor = (char *) item;
        busca_codigos_ibge_avl_nome(parv, cmp, resultComparador, valor, resultados);
    }
}

void busca_codigos_ibge_avl_latitude(tnode *parv, compara_ cmp, int resultComparador, double valor, tlistaencadeada **resultados) {
    tcidade fakeCidade;
    fakeCidade.latitude = valor;

    if (resultComparador == 0) {
        tnode *avlNode = avl_procura(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == -1) {
        tnode *avlNode = avl_procura_menores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == 1) {
        tnode *avlNode = avl_procura_maiores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = avlNode->dir;
        }
    }
}

void busca_codigos_ibge_avl_longitude(tnode *parv, compara_ cmp, int resultComparador, double valor, tlistaencadeada **resultados) {
    tcidade fakeCidade;
    fakeCidade.longitude = valor;

    if (resultComparador == 0) {
        tnode *avlNode = avl_procura(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == -1) {
        tnode *avlNode = avl_procura_menores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == 1) {
        tnode *avlNode = avl_procura_maiores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = avlNode->dir;
        }
    }
}

void busca_codigos_ibge_avl_codigo_uf(tnode *parv, compara_ cmp, int resultComparador, int valor, tlistaencadeada **resultados) {
    tcidade fakeCidade;
    fakeCidade.codigo_uf = valor;

    if (resultComparador == 0) {
        tnode *avlNode = avl_procura(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == -1) {
        tnode *avlNode = avl_procura_menores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == 1) {
        tnode *avlNode = avl_procura_maiores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = avlNode->dir;
        }
    }
}

void busca_codigos_ibge_avl_ddd(tnode *parv, compara_ cmp, int resultComparador, int valor, tlistaencadeada **resultados) {
    tcidade fakeCidade;
    fakeCidade.ddd = valor;

    if (resultComparador == 0) {
        tnode *avlNode = avl_procura(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == -1) {
        tnode *avlNode = avl_procura_menores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == 1) {
        tnode *avlNode = avl_procura_maiores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = avlNode->dir;
        }
    }
}

void busca_codigos_ibge_avl_nome(tnode *parv, compara_ cmp, int resultComparador, char *valor, tlistaencadeada **resultados) {
    tcidade fakeCidade;
    strcpy(fakeCidade.nome, valor);

    if (resultComparador == 0) {
        tnode *avlNode = avl_procura(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == -1) {
        tnode *avlNode = avl_procura_menores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = sucessor(avlNode);
        }
    } else if (resultComparador == 1) {
        tnode *avlNode = avl_procura_maiores(parv, fakeCidade, cmp);
        while (avlNode != NULL) {
            encadeada_insere(resultados, avlNode->item);
            avlNode = avlNode->dir;
        }
    }
}
