// 2022-08-19 11:02
#ifndef BUMP_POINTER_MALLOC_H
#define BUMP_POINTER_MALLOC_H
#include <stddef.h>
void init_default_mspace(void* base, size_t capacity);
void* malloc(size_t n);
static inline void free(void* mem) { __builtin_trap(); }
#endif  // BUMP_POINTER_MALLOC_H
