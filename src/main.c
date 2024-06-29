#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/avl.h"
#include "../include/cidade.h"
#include "../include/lista_encadeada.h"
#include "../include/hash.h"
#include "../include/utils.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Obrigatorio ter 1 parametros\n");
        return EXIT_FAILURE;
    }

    FILE *cidadesJson = fopen(argv[1], "r");
    if (cidadesJson == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    thash hash_cidades;
    if (hash_constroi(&hash_cidades, 12000, get_key_cidade) != EXIT_SUCCESS) {
        printf("Erro ao criar a tabela hash\n");
        fclose(cidadesJson);
        return EXIT_FAILURE;
    }

    tnode *avl_nome = NULL;
    tnode *avl_latitude = NULL;
    tnode *avl_longitude = NULL;
    tnode *avl_codigo_uf = NULL;
    tnode *avl_ddd = NULL;

    char linha[128];
    char dados[1024] = "";
    int count = 0;
    while (fgets(linha, sizeof(linha), cidadesJson) != NULL)
    {
        if (isValidLine(linha))
        {
            continue;
        }

        strcpy(linha, linha + 8);

        strcat(dados, linha);
        count++;

        if (count == 9)
        {
            tcidade *cidade = criar_cidade(dados);
            tnomecidade *nome_cidade = criar_nome_cidade(dados);
            tlatitudecidade *latitude_cidade = criar_latitude_cidade(dados);
            tlongitudecidade *longitude_cidade = criar_longitude_cidade(dados);
            tcodigoufdecidade *codigo_uf_cidade = criar_codigo_uf_cidade(dados);
            tdddcidade *ddd_cidade = criar_ddd_cidade(dados);

            if (hash_insere(&hash_cidades, cidade) == EXIT_FAILURE) {
                printf("Erro ao inserir a cidade na hash\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_nome, nome_cidade, compara_nome) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por nome\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_latitude, latitude_cidade, compara_latitude) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por latitude\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_longitude, longitude_cidade, compara_longitude) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por longitude\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_codigo_uf, codigo_uf_cidade, compara_codigo_uf) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por codigo_uf\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_ddd, ddd_cidade, compara_ddd) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por ddd\n");
                return EXIT_FAILURE;
            }

            free(cidade);
            free(nome_cidade);
            free(latitude_cidade);
            free(longitude_cidade);
            free(codigo_uf_cidade);
            free(ddd_cidade);

            dados[0] = '\0';
            count = 0;
        }
    }

    fclose(cidadesJson);

    hash_destroi(&hash_cidades);
    avl_destroi(avl_nome);
    avl_destroi(avl_latitude);
    avl_destroi(avl_longitude);
    avl_destroi(avl_codigo_uf);
    avl_destroi(avl_ddd);

    return EXIT_SUCCESS;
}
