#ifndef MALLOC_H
#define MALLOC_H
#include "dlmalloc.h"

#ifndef USE_HXD_PREFIX
#define hxd_malloc malloc
#define hxd_free free
#endif

#ifdef DDEBUG_HIST
#include <stdio.h>
#endif

static void* default_mspace;
static inline void init_default_mspace(void* base, size_t capacity) {
    default_mspace = create_mspace_with_base(base, capacity, 0);
}

static inline void* hxd_malloc(size_t n) {
#ifdef DEBUG_HIST
    printf("HIST:ALLOC:%ld\n", n);
    size_t* ret = (size_t*)mspace_malloc(default_mspace, n + sizeof(size_t));
    *ret = n;
    return (void*)(ret + 1);
#else
    return mspace_malloc(default_mspace, n);
#endif
}

static inline void hxd_free(void* mem) {
#ifdef DEBUG_HIST
    size_t* orig = (size_t*)mem - 1;
    size_t n = *orig;
    printf("HIST:DEALLOC:%ld\n", n);
    mspace_free(default_mspace, (void*)orig);
#else
    mspace_free(default_mspace, mem);
#endif
}

#endif  // MALLOC_H
