#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/queries.h"
#include "../include/cidade.h"

void busca_codigos_ibge_avl(tnode *parv, const char *comparador, titem item, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    if (item.tipo == TIPO_LATITUDE)
    {
        busca_codigos_ibge_avl_latitude(parv, comparador, &item.latitudecidade, resultados);
    }
    else if (item.tipo == TIPO_LONGITUDE)
    {
        // Função específica para longitude
    }
    else if (item.tipo == TIPO_CODIGO_UF)
    {
        // Função específica para código UF
    }
    else if (item.tipo == TIPO_DDD)
    {
        // Função específica para DDD
    }
    else if (item.tipo == TIPO_NOME)
    {
        busca_codigos_ibge_avl_nome(parv, comparador, &item.nomecidade, resultados);
    }
}

// Funções específicas de busca por latitude
void busca_codigos_ibge_avl_latitude(tnode *parv, const char *comparador, tlatitudecidade *item, tlistaencadeada **resultados)
{
    if (strcmp(comparador, "==") == 0)
    {
        busca_codigos_ibge_avl_latitude_igual_a(parv, item->latitude, resultados);
    }
    else if (strcmp(comparador, "<") == 0)
    {
        busca_codigos_ibge_avl_latitude_menor_que(parv, item->latitude, resultados);
    }
    else if (strcmp(comparador, "<=") == 0)
    {
        busca_codigos_ibge_avl_latitude_menor_igual(parv, item->latitude, resultados);
    }
    else if (strcmp(comparador, ">") == 0)
    {
        busca_codigos_ibge_avl_latitude_maior_que(parv, item->latitude, resultados);
    }
    else if (strcmp(comparador, ">=") == 0)
    {
        busca_codigos_ibge_avl_latitude_maior_igual(parv, item->latitude, resultados);
    }
    else if (strcmp(comparador, "!=") == 0)
    {
        busca_codigos_ibge_avl_latitude_diferente_de(parv, item->latitude, resultados);
    }
    else
    {
        printf("Digite um comparador válido (==, <, <=, >, >=, !=)\n\n");
    }
}

void busca_codigos_ibge_avl_latitude_maior_que(tnode *parv, double x, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_latitude_maior_que(parv->esq, x, resultados);

    tlatitudecidade *cidade = (tlatitudecidade *)parv->item;
    if (cidade->latitude > x)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_latitude_maior_que(parv->dir, x, resultados);
}

void busca_codigos_ibge_avl_latitude_igual_a(tnode *parv, double x, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_latitude_igual_a(parv->esq, x, resultados);

    tlatitudecidade *cidade = (tlatitudecidade *)parv->item;
    if (cidade->latitude == x)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_latitude_igual_a(parv->dir, x, resultados);
}

void busca_codigos_ibge_avl_latitude_menor_que(tnode *parv, double x, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_latitude_menor_que(parv->esq, x, resultados);

    tlatitudecidade *cidade = (tlatitudecidade *)parv->item;
    if (cidade->latitude < x)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_latitude_menor_que(parv->dir, x, resultados);
}

void busca_codigos_ibge_avl_latitude_menor_igual(tnode *parv, double x, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_latitude_menor_igual(parv->esq, x, resultados);

    tlatitudecidade *cidade = (tlatitudecidade *)parv->item;
    if (cidade->latitude <= x)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_latitude_menor_igual(parv->dir, x, resultados);
}

void busca_codigos_ibge_avl_latitude_maior_igual(tnode *parv, double x, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_latitude_maior_igual(parv->esq, x, resultados);

    tlatitudecidade *cidade = (tlatitudecidade *)parv->item;
    if (cidade->latitude >= x)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_latitude_maior_igual(parv->dir, x, resultados);
}

void busca_codigos_ibge_avl_latitude_diferente_de(tnode *parv, double x, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_latitude_diferente_de(parv->esq, x, resultados);

    tlatitudecidade *cidade = (tlatitudecidade *)parv->item;
    if (cidade->latitude != x)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_latitude_diferente_de(parv->dir, x, resultados);
}

// Funções específicas de busca por nome
void busca_codigos_ibge_avl_nome(tnode *parv, const char *comparador, tnomecidade *item, tlistaencadeada **resultados)
{
    if (strcmp(comparador, "==") == 0)
    {
        busca_codigos_ibge_avl_nome_igual_a(parv, item->nome, resultados);
    }
    else if (strcmp(comparador, "<") == 0)
    {
        busca_codigos_ibge_avl_nome_menor_que(parv, item->nome, resultados);
    }
    else if (strcmp(comparador, "<=") == 0)
    {
        busca_codigos_ibge_avl_nome_menor_igual(parv, item->nome, resultados);
    }
    else if (strcmp(comparador, ">") == 0)
    {
        busca_codigos_ibge_avl_nome_maior_que(parv, item->nome, resultados);
    }
    else if (strcmp(comparador, ">=") == 0)
    {
        busca_codigos_ibge_avl_nome_maior_igual(parv, item->nome, resultados);
    }
    else if (strcmp(comparador, "!=") == 0)
    {
        busca_codigos_ibge_avl_nome_diferente_de(parv, item->nome, resultados);
    }
    else
    {
        printf("Digite um comparador válido (==, <, <=, >, >=, !=)\n\n");
    }
}

void busca_codigos_ibge_avl_nome_igual_a(tnode *parv, const char *nome, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_nome_igual_a(parv->esq, nome, resultados);

    tnomecidade *cidade = (tnomecidade *)parv->item;
    if (strcmp(cidade->nome, nome) == 0)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_nome_igual_a(parv->dir, nome, resultados);
}

void busca_codigos_ibge_avl_nome_menor_que(tnode *parv, const char *nome, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_nome_menor_que(parv->esq, nome, resultados);

    tnomecidade *cidade = (tnomecidade *)parv->item;
    if (strcmp(cidade->nome, nome) < 0)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_nome_menor_que(parv->dir, nome, resultados);
}

void busca_codigos_ibge_avl_nome_menor_igual(tnode *parv, const char *nome, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_nome_menor_igual(parv->esq, nome, resultados);

    tnomecidade *cidade = (tnomecidade *)parv->item;
    if (strcmp(cidade->nome, nome) <= 0)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_nome_menor_igual(parv->dir, nome, resultados);
}

void busca_codigos_ibge_avl_nome_maior_que(tnode *parv, const char *nome, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_nome_maior_que(parv->esq, nome, resultados);

    tnomecidade *cidade = (tnomecidade *)parv->item;
    if (strcmp(cidade->nome, nome) > 0)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_nome_maior_que(parv->dir, nome, resultados);
}

void busca_codigos_ibge_avl_nome_maior_igual(tnode *parv, const char *nome, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_nome_maior_igual(parv->esq, nome, resultados);

    tnomecidade *cidade = (tnomecidade *)parv->item;
    if (strcmp(cidade->nome, nome) >= 0)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_nome_maior_igual(parv->dir, nome, resultados);
}

void busca_codigos_ibge_avl_nome_diferente_de(tnode *parv, const char *nome, tlistaencadeada **resultados)
{
    if (parv == NULL)
    {
        return;
    }

    busca_codigos_ibge_avl_nome_diferente_de(parv->esq, nome, resultados);

    tnomecidade *cidade = (tnomecidade *)parv->item;
    if (strcmp(cidade->nome, nome) != 0)
    {
        encadeada_insere(resultados, &cidade->codigo_ibge);
    }

    busca_codigos_ibge_avl_nome_diferente_de(parv->dir, nome, resultados);
}
