// 2022-08-19 11:02
#ifndef POOL_MALLOC_H
#define POOL_MALLOC_H
#include <stddef.h>

#include "../common.h"

void init_spaces();
void* hxd_malloc(size_t n);
void* hxd_calloc(size_t n, size_t size);
void hxd_free(void* mem);

#endif  // POOL_MALLOC_H
