#ifndef __ENCADEADA__
#define __ENCADEADA__

typedef struct _listaencadeada {
    int codigo_ibge;
    struct _listaencadeada *prox;
} tlistaencadeada;

tlistaencadeada *encadeada_procura(tlistaencadeada *head, int codigo_ibge);
void encadeada_insere(tlistaencadeada **head, int codigo_ibge);
void encadeada_remove(tlistaencadeada **head, int codigo_ibge);
void encadeada_destroi(tlistaencadeada *head);

#endif
