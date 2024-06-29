#include <stdio.h>
#include <stdlib.h>

#include "../include/avl.h"
#include "../include/utils.h"
#include "../include/cidade.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Obrigatorio ter 3 parametros\n");
        return EXIT_FAILURE;
    }

    FILE *cidadesJson = fopen(argv[1], "r");
    if (cidadesJson == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
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
            titem *cidade = criar_cidade(dados);

            if (avl_insere(&avl_nome, *cidade, compara_nome) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por nome\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_latitude, *cidade, compara_latitude) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por latitude\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_longitude, *cidade, compara_longitude) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por longitude\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_codigo_uf, *cidade, compara_codigo_uf) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por codigo_uf\n");
                return EXIT_FAILURE;
            }

            if (avl_insere(&avl_ddd, *cidade, compara_ddd) == EXIT_FAILURE)
            {
                printf("Erro ao inserir a cidade na AVL por ddd\n");
                return EXIT_FAILURE;
            }

            dados[0] = '\0';
            count = 0;
        }
    }

    fclose(cidadesJson);

    avl_destroi(avl_nome);
    avl_destroi(avl_latitude);
    avl_destroi(avl_longitude);
    avl_destroi(avl_codigo_uf);
    avl_destroi(avl_ddd);

    return EXIT_SUCCESS;
}
