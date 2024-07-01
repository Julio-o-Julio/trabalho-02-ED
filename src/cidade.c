#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <regex.h>

#include "../include/cidade.h"

tcidade *criar_cidade(char dados[])
{
    tcidade *cidade = malloc(sizeof(tcidade));
    if (cidade == NULL)
    {
        printf("Erro ao alocar memória para a cidade\n");
        exit(EXIT_FAILURE);
    }

    char *next_field;

    next_field = strstr(dados, "\"codigo_ibge\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &cidade->codigo_ibge);
        }
    }

    next_field = strstr(dados, "\"nome\":");
    if (next_field != NULL)
    {
        regex_t regex;
        regmatch_t matches[2];
        char pattern[] = "\"nome\":\\s*\"([^\"]+)\"";

        if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        {
            printf("Erro ao compilar a expressão regular.\n");
            exit(EXIT_FAILURE);
        }

        if (regexec(&regex, next_field, 2, matches, 0) == 0)
        {
            int start = matches[1].rm_so;
            int end = matches[1].rm_eo;
            int length = end - start;

            strncpy(cidade->nome, next_field + start, length);
            cidade->nome[length] = '\0';
        }
        else
        {
            printf("Nome da cidade não encontrado.\n");
            exit(EXIT_FAILURE);
        }

        regfree(&regex);
    }

    next_field = strstr(dados, "\"latitude\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%lf", &cidade->latitude);
        }
    }

    next_field = strstr(dados, "\"longitude\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%lf", &cidade->longitude);
        }
    }

    next_field = strstr(dados, "\"capital\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &cidade->capital);
        }
    }

    next_field = strstr(dados, "\"codigo_uf\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &cidade->codigo_uf);
        }
    }

    next_field = strstr(dados, "\"siafi_id\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &cidade->siafi_id);
        }
    }

    next_field = strstr(dados, "\"ddd\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &cidade->ddd);
        }
    }

    next_field = strstr(dados, "\"fuso_horario\":");
    if (next_field != NULL)
    {
        regex_t regex;
        regmatch_t matches[2];
        char pattern[] = "\"fuso_horario\":\\s*\"([^\"]+)\"";

        if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        {
            printf("Erro ao compilar a expressão regular.\n");
            exit(EXIT_FAILURE);
        }

        if (regexec(&regex, next_field, 2, matches, 0) == 0)
        {
            int start = matches[1].rm_so;
            int end = matches[1].rm_eo;
            int length = end - start;

            strncpy(cidade->fuso_horario, next_field + start, length);
            cidade->fuso_horario[length] = '\0';
        }
        else
        {
            printf("Fuso horário não encontrado.\n");
            exit(EXIT_FAILURE);
        }

        regfree(&regex);
    }

    return cidade;
}
