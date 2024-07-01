#ifndef __QUERIES__
#define __QUERIES__

#include "../include/avl.h"
#include "../include/lista_encadeada.h"
#include "../include/cidade.h"

void busca_codigos_ibge_avl(tnode *parv, char *campo, compara_ cmp, void * item, tlistaencadeada **resultados);

#endif
