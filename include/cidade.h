#ifndef __CIDADE__
#define __CIDADE__

typedef struct _cidade {
    int codigo_ibge;
    char nome[64];
    int codigo_uf;
    int ddd;
    double latitude;
    double longitude;
    int capital;
    int siafi_id;
    char fuso_horario[64];
} tcidade;

tcidade *criar_cidade(char *dados);

#endif
