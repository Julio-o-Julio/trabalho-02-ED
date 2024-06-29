#ifndef __CIDADE__
#define __CIDADE__

typedef struct _cidade
{
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

typedef struct _nomecidade
{
    int codigo_ibge;
    char nome[64];
} tnomecidade;

typedef struct _latitudecidade
{
    int codigo_ibge;
    double latitude;
} tlatitudecidade;

typedef struct _longitudecidade
{
    int codigo_ibge;
    double longitude;
} tlongitudecidade;

typedef struct _codigoufcidade
{
    int codigo_ibge;
    int codigo_uf;
} tcodigoufdecidade;

typedef struct _dddcidade
{
    int codigo_ibge;
    int ddd;
} tdddcidade;

tcidade *criar_cidade(char *dados);
tnomecidade *criar_nome_cidade(char *dados);
tlatitudecidade *criar_latitude_cidade(char *dados);
tlongitudecidade *criar_longitude_cidade(char *dados);
tcodigoufdecidade *criar_codigo_uf_cidade(char *dados);
tdddcidade *criar_ddd_cidade(char *dados);

#endif
