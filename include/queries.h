#ifndef __QUERIES__
#define __QUERIES__

#include "../include/avl.h"
#include "../include/lista_encadeada.h"
#include "../include/cidade.h"

void busca_codigos_ibge_avl(tnode *parv, const char *comparador, titem item, tlistaencadeada **resultados);

void busca_codigos_ibge_avl_latitude(tnode *parv, const char *comparador, tlatitudecidade *item, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_latitude_maior_que(tnode *parv, double x, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_latitude_igual_a(tnode *parv, double x, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_latitude_menor_que(tnode *parv, double x, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_latitude_menor_igual(tnode *parv, double x, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_latitude_maior_igual(tnode *parv, double x, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_latitude_diferente_de(tnode *parv, double x, tlistaencadeada **resultados);

void busca_codigos_ibge_avl_nome(tnode *parv, const char *comparador, tnomecidade *item, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome_igual_a(tnode *parv, const char *nome, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome_menor_que(tnode *parv, const char *nome, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome_menor_igual(tnode *parv, const char *nome, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome_maior_que(tnode *parv, const char *nome, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome_maior_igual(tnode *parv, const char *nome, tlistaencadeada **resultados);
void busca_codigos_ibge_avl_nome_diferente_de(tnode *parv, const char *nome, tlistaencadeada **resultados);

#endif
