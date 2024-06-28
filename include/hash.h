#ifndef __HASH__
#define __HASH__

typedef struct _hash {
    int codigo_ibge;
    struct _hash *next;
} thash;

typedef struct _hashtable {
    int size;
    thash **table;
} thashtable;

thash *hash_table_search(thashtable *ht, int codigo_ibge);
void hash_table_insert(thashtable *ht, int codigo_ibge);
void hash_table_delete(thashtable *ht, int codigo_ibge);
void hash_table_free(thashtable *ht);

#endif
