// 2022-08-19 11:02
#ifndef BUMP_POINTER_MALLOC_H
#define BUMP_POINTER_MALLOC_H
#include <stddef.h>
#include <string.h>
#include "../common.h"

void init_default_mspace(void* base, size_t capacity);

void* hxd_malloc(size_t n);
static inline void* hxd_calloc(size_t n) {
    void* ret = hxd_malloc(n);
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, n);
    return ret;
}
static inline void free(void* mem) {}
#endif  // BUMP_POINTER_MALLOC_H
