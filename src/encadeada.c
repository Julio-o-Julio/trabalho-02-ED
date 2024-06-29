#include <stdio.h>
#include <stdlib.h>

#include "../include/lista_encadeada.h"

tlistaencadeada *encadeada_procura(tlistaencadeada *head, titem item, compara_ cmp)
{
    while (head != NULL)
    {
        if (cmp(head->item, item) == 0)
        {
            return head;
        }
        head = head->prox;
    }
    return NULL;
}

void encadeada_insere(tlistaencadeada **head, titem item)
{
    tlistaencadeada *novo = (tlistaencadeada *)malloc(sizeof(tlistaencadeada));
    if (!novo)
    {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novo->item = item;
    novo->prox = *head;
    *head = novo;
}

void encadeada_remove(tlistaencadeada **head, titem item, compara_ cmp)
{
    tlistaencadeada *temp = *head, *prev = NULL;

    if (temp != NULL && cmp(temp->item, item) == 0)
    {
        *head = temp->prox;
        free(temp);
        return;
    }

    while (temp != NULL && cmp(temp->item, item) != 0)
    {
        prev = temp;
        temp = temp->prox;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->prox = temp->prox;
    free(temp);
}

void encadeada_destroi(tlistaencadeada *head)
{
    tlistaencadeada *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->prox;
        free(temp);
    }
}
