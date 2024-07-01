#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/queries.h"
#include "../include/cidade.h"

void busca_codigos_ibge_avl(tnode *parv, char *campo, compara_ cmp, void * item, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        printf("Erro ao buscar %s Arvore vazia!", (char *) item);
        return;
    }

    if (strcmp(campo, "latitude") || strcmp(campo, "longitude"))
    {
        /* transforma a variável item em double */
    } else if (strcmp(campo, "ddd") || strcmp(campo, "codigo_uf"))
    {
        /* transforma a variável item em int */
    } else if (strcmp(campo, "nome"))
    {
        /* transforma a variável item em char * */
    }
}
