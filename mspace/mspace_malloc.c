#include "mspace_malloc.h"

#ifdef DEBUG_HIST
#include "../printf.h"
#include "unistd.h"
void _putchar(char character) { write(1, &character, 1); }
#endif

static void* default_mspace;

void init_default_mspace(void* base, size_t capacity) {
    default_mspace = create_mspace_with_base(base, capacity, 0);
}

void* hxd_malloc(size_t n) {
    if (n == 0) {
        return NULL;
    }
#ifdef DEBUG_HIST
    // NOTE: pool_malloc has an `int` header for every malloc, on both m32 and
    // m64
    printf("HIST:ALLOC:%ld\n", n + 4);
    size_t* ret = (size_t*)mspace_malloc(default_mspace, n + sizeof(size_t));
    *ret = n;
    return (void*)(ret + 1);
#else
    return mspace_malloc(default_mspace, n);
#endif
}

void* hxd_calloc(size_t n, size_t size) {
    void* ret = hxd_malloc(n * size);
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, n);
    return ret;
}

void hxd_free(void* mem) {
    if (mem == NULL) {
        return;
    }
#ifdef DEBUG_HIST
    size_t* orig = (size_t*)mem - 1;
    size_t n = *orig;
    printf("HIST:DEALLOC:%ld\n", n + 4);
    mspace_free(default_mspace, (void*)orig);
#else
    mspace_free(default_mspace, mem);
#endif
}
