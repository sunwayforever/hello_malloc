#include "pool_malloc.h"

#include <stdio.h>

#define ALIGNMENT 8

static inline void* align_ptr(void* value) {
    return (
        void*)((((unsigned long int)value + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT);
}

static inline size_t align_num(size_t value, size_t align) {
    return ((value + align - 1) / align) * align;
}

extern void* POOLS[];
extern size_t BIN_SIZE;
void* hxd_malloc(size_t n) {
    if (n == 0) {
        return NULL;
    }
    n += sizeof(int);
    int bin = align_num(n, BIN_SIZE) / BIN_SIZE;
    Pool* pool = POOLS[bin];
    int* ret = pool_malloc(pool);
    if (ret == NULL) {
        return NULL;
    }
    *ret = bin;
    return (void*)(ret + 1);
}

void hxd_free(void* mem) {
    if (mem == NULL) {
        return;
    }
    int* orig = (int*)mem - 1;
    int bin = *orig;
    Pool* pool = POOLS[bin];
    pool_free(pool, orig);
}

Pool* init_pool(void* base, size_t capacity, size_t size, size_t count) {
    Pool* pool = (Pool*)base;
    base += sizeof(Pool);
    pool->free_list = align_ptr(base);
    size = align_num(size, ALIGNMENT);
    struct Chunk* current = pool->free_list;
    for (int i = 0; i < count - 1; i++) {
        struct Chunk* next = (struct Chunk*)((void*)current + size);
        current->next = next;
        current = next;
    }
    current->next = NULL;

    if ((void*)current + size - (void*)pool > capacity) {
        __builtin_trap();
    }
    return pool;
}

void* pool_malloc(Pool* pool) {
    struct Chunk* head = pool->free_list;
    if (head == NULL) {
        return NULL;
    }
    struct Chunk* next = head->next;
    ((Pool*)pool)->free_list = next;
    return (void*)head;
}

void pool_free(Pool* pool, void* mem) {
    struct Chunk* head = pool->free_list;
    ((Pool*)pool)->free_list = (struct Chunk*)mem;
    ((struct Chunk*)mem)->next = head;
}
