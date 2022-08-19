#include <stdio.h>

#include "pool_malloc.h"

char buffer[32 * 10];
Pool pool;

int main(int argc, char *argv[]) {
    init_pool(&pool, buffer, 32, 10);
    for (int i = 0; i < 11; i++) {
        void *x = pool_malloc(&pool);
        printf("%p\n", x);
    }

    init_pool(&pool, buffer, 32, 10);
    for (int i = 0; i < 10; i++) {
        void *x = pool_malloc(&pool);
        printf("%p\n", x);
        pool_free(&pool, x);
    }

    printf("\n");
}
