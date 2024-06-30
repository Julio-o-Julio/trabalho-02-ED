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

tnomecidade *criar_nome_cidade(char *dados)
{
    tnomecidade *nome_cidade = malloc(sizeof(tnomecidade));
    if (nome_cidade == NULL)
    {
        printf("Erro ao alocar memória para a nome_cidade\n");
        exit(EXIT_FAILURE);
    }

    char *next_field;

    next_field = strstr(dados, "\"codigo_ibge\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &nome_cidade->codigo_ibge);
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

            strncpy(nome_cidade->nome, next_field + start, length);
            nome_cidade->nome[length] = '\0';
        }
        else
        {
            printf("Nome da cidade não encontrado.\n");
            exit(EXIT_FAILURE);
        }

        regfree(&regex);
    }

    return nome_cidade;
}

tlatitudecidade *criar_latitude_cidade(char *dados)
{
    tlatitudecidade *latitude_cidade = malloc(sizeof(tlatitudecidade));
    if (latitude_cidade == NULL)
    {
        printf("Erro ao alocar memória para a latitude_cidade\n");
        exit(EXIT_FAILURE);
    }

    char *next_field;

    next_field = strstr(dados, "\"codigo_ibge\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &latitude_cidade->codigo_ibge);
        }
    }

    next_field = strstr(dados, "\"latitude\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%lf", &latitude_cidade->latitude);
        }
    }

    return latitude_cidade;
}

tlongitudecidade *criar_longitude_cidade(char *dados)
{
    tlongitudecidade *longitude_cidade = malloc(sizeof(tlongitudecidade));
    if (longitude_cidade == NULL)
    {
        printf("Erro ao alocar memória para a longitude_cidade\n");
        exit(EXIT_FAILURE);
    }

    char *next_field;

    next_field = strstr(dados, "\"codigo_ibge\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &longitude_cidade->codigo_ibge);
        }
    }

    next_field = strstr(dados, "\"longitude\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%lf", &longitude_cidade->longitude);
        }
    }

    return longitude_cidade;
}

tcodigoufcidade *criar_codigo_uf_cidade(char *dados)
{
    tcodigoufcidade *codigo_uf_cidade = malloc(sizeof(tcodigoufcidade));
    if (codigo_uf_cidade == NULL)
    {
        printf("Erro ao alocar memória para a codigo_uf_cidade\n");
        exit(EXIT_FAILURE);
    }

    char *next_field;

    next_field = strstr(dados, "\"codigo_ibge\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &codigo_uf_cidade->codigo_ibge);
        }
    }

    next_field = strstr(dados, "\"codigo_uf\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &codigo_uf_cidade->codigo_uf);
        }
    }

    return codigo_uf_cidade;
}

tdddcidade *criar_ddd_cidade(char *dados)
{
    tdddcidade *ddd_cidade = malloc(sizeof(tdddcidade));
    if (ddd_cidade == NULL)
    {
        printf("Erro ao alocar memória para a ddd_cidade\n");
        exit(EXIT_FAILURE);
    }

    char *next_field;

    next_field = strstr(dados, "\"codigo_ibge\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &ddd_cidade->codigo_ibge);
        }
    }

    next_field = strstr(dados, "\"ddd\":");
    if (next_field != NULL)
    {
        next_field = strchr(next_field, ':');
        if (next_field != NULL)
        {
            sscanf(next_field + 1, "%d", &ddd_cidade->ddd);
        }
    }

    return ddd_cidade;
}
