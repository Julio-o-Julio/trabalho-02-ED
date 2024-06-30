#ifndef __TITEM__
#define __TITEM__

#include "./cidade.h"

typedef enum
{
    TIPO_LATITUDE,
    TIPO_LONGITUDE,
    TIPO_CODIGO_UF,
    TIPO_DDD,
    TIPO_NOME
} tipo_item;

typedef struct
{
    tipo_item tipo;
    union
    {
        tlatitudecidade latitudecidade;
        tlongitudecidade longitudecidade;
        tcodigoufcidade codigoufcidade;
        tdddcidade dddcidade;
        tnomecidade nomecidade;
    };
} titem;

#endif
