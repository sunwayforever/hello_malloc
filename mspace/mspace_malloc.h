#ifndef MALLOC_H
#define MALLOC_H
#include "../common.h"
#include "dlmalloc.h"

void* hxd_malloc(size_t n);
void* hxd_calloc(size_t n, size_t size);
void hxd_free(void* mem);

#endif  // MALLOC_H
