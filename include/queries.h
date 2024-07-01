#ifndef __QUERIES__
#define __QUERIES__

#include "../include/avl.h"
#include "../include/lista_encadeada.h"
#include "../include/cidade.h"

void busca_codigos_ibge_avl(tnode *parv, char *campo, compara_ cmp, char *comparador, void * item, tlistaencadeada **resultados);

void busca_codigos_ibge_avl_latitude(tnode *parv, compara_ cmp, int resultComparador, double valor, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_longitude(tnode *parv, compara_ cmp, int resultComparador, double valor, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_codigo_uf(tnode *parv, compara_ cmp, int resultComparador, int valor, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_ddd(tnode *parv, compara_ cmp, int resultComparador, int valor, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome(tnode *parv, compara_ cmp, int resultComparador, char * valor, tlistaencadeada **resultados);

#endif
