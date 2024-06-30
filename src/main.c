#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/avl.h"
#include "../include/cidade.h"
#include "../include/lista_encadeada.h"
#include "../include/hash.h"
#include "../include/utils.h"
#include "../include/queries.h"
#include "../include/titem.h"

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

            titem nome_item = {TIPO_NOME, .nomecidade = criar_nome_cidade(dados)};
            titem latitude_item = {TIPO_LATITUDE, .latitudecidade = criar_latitude_cidade(dados)};
            titem longitude_item = {TIPO_LONGITUDE, .longitudecidade = criar_longitude_cidade(dados)};
            titem codigo_uf_item = {TIPO_CODIGO_UF, .codigoufcidade = criar_codigo_uf_cidade(dados)};
            titem ddd_item = {TIPO_DDD, .dddcidade = criar_ddd_cidade(dados)};

            if (hash_insere(&hash_cidades, cidade) == EXIT_FAILURE) {
                printf("Erro ao inserir a cidade na hash\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_nome, nome_item, compara_nome) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por nome\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_latitude, latitude_item, compara_latitude) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por latitude\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_longitude, longitude_item, compara_longitude) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por longitude\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_codigo_uf, codigo_uf_item, compara_codigo_uf) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por codigo_uf\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_ddd, ddd_item, compara_ddd) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por ddd\n");
                return EXIT_FAILURE;
            }

            dados[0] = '\0';
            count = 0;
        }
    }

    fclose(cidadesJson);

    tlistaencadeada *resultados = NULL;

    int response = -1;
    while (response != 0)
    {
        printf("Interface iniciada:\n\n");

        printf(" 0. Para sair da interface\n");
        printf(" 1. Para retornar a resposta da tarefa 3 (combinação de  range queries)\n\n");
        printf(" ");
        scanf("%d", &response);

        switch (response)
        {
        case 0:
            response = 0;
            break;
        case 1:
            /* (1) cidades com latitude > 50, (2) 20 <longitude < 30 e (3) DDD == 67 */
            titem lat_query = {TIPO_LATITUDE, .latitudecidade = { .latitude = 50 }};
            titem long_query_min = {TIPO_LONGITUDE, .longitudecidade = { .longitude = 20 }};
            titem long_query_max = {TIPO_LONGITUDE, .longitudecidade = { .longitude = 30 }};
            titem ddd_query = {TIPO_DDD, .dddcidade = { .ddd = 67 }};
            
            busca_codigos_ibge_avl(avl_latitude, ">", lat_query, &resultados);
            busca_codigos_ibge_avl(avl_longitude, ">", long_query_min, &resultados);
            busca_codigos_ibge_avl(avl_longitude, "<", long_query_max, &resultados);
            busca_codigos_ibge_avl(avl_ddd, "==", ddd_query, &resultados);
            break;
        default:
            printf("\n Responda um numero de 0 a 5\n\n");
            break;
        }
    }

    hash_destroi(&hash_cidades);
    avl_destroi(avl_nome);
    avl_destroi(avl_latitude);
    avl_destroi(avl_longitude);
    avl_destroi(avl_codigo_uf);
    avl_destroi(avl_ddd);

    return EXIT_SUCCESS;
}
