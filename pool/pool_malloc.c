#include "pool_malloc.h"

#include <stdio.h>

#define ALIGNMENT 4

static inline void* align_ptr(void* value) {
    return (
        void*)((((unsigned long int)value + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT);
}

void init_pool(Pool* pool, void* base, size_t size, size_t count) {
    pool->free_list = align_ptr(base);
    struct Chunk* current = pool->free_list;
    for (int i = 0; i < count - 1; i++) {
        struct Chunk* next = (struct Chunk*)((void*)current + size);
        current->next = next;
        current = next;
    }
    current->next = NULL;
}

void* pool_malloc(Pool* pool) {
    struct Chunk* head = pool->free_list;
    if (head == NULL) {
        return NULL;
    }
    struct Chunk* next = head->next;
    pool->free_list = next;
    return (void*)head;
}

void pool_free(Pool* pool, void* mem) {
    struct Chunk* head = pool->free_list;
    pool->free_list = (struct Chunk*)mem;
    ((struct Chunk*)mem)->next = head;
}
