// 2022-08-18 14:24
#ifndef MALLOC_H
#define MALLOC_H

#include "mspace_malloc.h"

void* default_mspace;

inline void init_default_mspace(void* base, size_t capacity) {
    default_mspace = create_mspace_with_base(base, 10240, 0);
}

void* malloc(size_t n) { return mspace_malloc(default_mspace, n); }
void free(void* mem) { mspace_free(default_mspace, mem); }

#endif  // MALLOC_H
