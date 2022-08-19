#include <stdio.h>

#include "pool_malloc.h"

char buffer[32 * 10 + sizeof(Pool)];

int main(int argc, char *argv[]) {
    Pool *pool = init_pool(buffer, sizeof(buffer), 32, 10);
    for (int i = 0; i < 11; i++) {
        void *x = pool_malloc(pool);
        printf("%p\n", x);
    }

    pool = init_pool(buffer, sizeof(buffer), 32, 10);
    for (int i = 0; i < 10; i++) {
        void *x = pool_malloc(pool);
        printf("%p\n", x);
        pool_free(pool, x);
    }

    printf("\n");
}
