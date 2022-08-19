#ifndef MALLOC_H
#define MALLOC_H
#include "dlmalloc.h"

static void* default_mspace;
static inline void init_default_mspace(void* base, size_t capacity) {
    default_mspace = create_mspace_with_base(base, capacity, 0);
}

static inline void* malloc(size_t n) {
    return mspace_malloc(default_mspace, n);
}

static inline void free(void* mem) { mspace_free(default_mspace, mem); }

#endif  // MALLOC_H
