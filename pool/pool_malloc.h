// 2022-08-19 11:02
#ifndef POOL_MALLOC_H
#define POOL_MALLOC_H
#include <stddef.h>
#include "../common.h"

struct Chunk {
    struct Chunk* next;
};

typedef struct {
    struct Chunk* free_list;
    size_t size;
} Pool;

Pool* init_pool(void* base, size_t capacity, size_t size, size_t count);

void* pool_malloc(Pool* pool);
void* pool_calloc(Pool* pool);
void pool_free(Pool* pool, void* mem);

void* hxd_malloc(size_t n);
void hxd_free(void* mem);

#endif  // POOL_MALLOC_H
