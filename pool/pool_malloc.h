// 2022-08-19 11:02
#ifndef BUMP_POINTER_MALLOC_H
#define BUMP_POINTER_MALLOC_H
#include <stddef.h>
struct Chunk {
    struct Chunk* next;
};

typedef struct {
    struct Chunk* free_list;
} Pool;

void init_pool(Pool* pool, void* base, size_t size, size_t count);
void* pool_malloc(Pool* pool);
void pool_free(Pool* pool, void* mem);
static inline void free(void* mem) { __builtin_trap(); }
#endif  // BUMP_POINTER_MALLOC_H
