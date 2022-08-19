#include "bump_pointer_malloc.h"

#include <stdio.h>

static void* buffer;
static size_t buffer_size;
static size_t current_offset;

#define ALIGNMENT 4

static inline void* align_ptr(void* value) {
    return (
        void*)((((unsigned long int)value + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT);
}

static inline size_t align_num(size_t value) {
    return ((value + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT;
}

void init_default_mspace(void* base, size_t capacity) {
    buffer_size = capacity;
    current_offset = 0;
    buffer = align_ptr(base);
}

void* malloc(size_t n) {
    if (current_offset + n > buffer_size) {
        return NULL;
    }
    void* ret = buffer + current_offset;
    current_offset = align_num(current_offset + n);
    return ret;
}
