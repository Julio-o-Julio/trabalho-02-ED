#ifndef __INTERFACE__
#define __INTERFACE__

#include "avl.h"

void range_query_avl(tnode *root, titem limite_inferior, titem limite_superior);
void combinar_queries(tnode *avl_nome, tnode *avl_latitude, tnode *avl_longitude);

#endif
