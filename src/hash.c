#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "../include/hash.h"

#define SEED 0x12345678

uint32_t hashf(const char *str, uint32_t h)
{
    for (; *str; ++str)
    {
        h ^= *str;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}

int hash_insere(thash *h, void *bucket)
{
    char *key = h->get_key(bucket);
    uint32_t hash = hashf(key, SEED);
    free(key);

    int pos = hash % h->max;
    int original_pos = pos;
    int i = 1;

    while (h->table[pos] != 0)
    {
        if (h->table[pos] == h->deleted)
            break;

        char *existing_key = h->get_key((void *)h->table[pos]);
        if (strcmp(existing_key, key) == 0)
        {
            printf("Chave já existe na posição %d\n", pos);
            free(existing_key);
            free(bucket);
            return EXIT_FAILURE;
        }
        free(existing_key);

        pos = (original_pos + i * i) % h->max;
        i++;
    }

    h->table[pos] = (uintptr_t)bucket;
    h->size += 1;
    return EXIT_SUCCESS;
}

int hash_constroi(thash *h, int nbuckets, char *(*get_key)(void *))
{
    h->table = calloc(nbuckets + 1, sizeof(void *));
    if (h->table == NULL)
    {
        return EXIT_FAILURE;
    }
    h->max = nbuckets + 1;
    h->size = 0;
    h->deleted = (uintptr_t)&(h->size);
    h->get_key = get_key;

    return EXIT_SUCCESS;
}

void *hash_procura(thash *h, const char *key)
{
    int pos = hashf(key, SEED) % h->max;
    void *ret = NULL;

    while (h->table[pos] != 0 && ret == NULL)
    {
        char *existing_key = h->get_key((void *)h->table[pos]);
        if (strcmp(existing_key, key) == 0)
        {
            ret = (void *)h->table[pos];
        }
        free(existing_key);

        if (ret == NULL)
        {
            pos = (pos + 1) % h->max;
        }
    }
    return ret;
}

void hash_destroi(thash *h)
{
    for (int pos = 0; pos < h->max; pos++)
    {
        if (h->table[pos] != 0 && h->table[pos] != h->deleted)
        {
            free((void *)h->table[pos]);
        }
    }
    free(h->table);
}
