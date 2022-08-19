#include <stdio.h>
#include <string.h>

#include "pool_malloc.h"

//  NOTE: internally `Pool` object itself resides at the beginning of `buffer`
char buffer[32 * 10 + 16];

int main(int argc, char *argv[]) {
    /* NOTE: due to data alignment, runtime error will be thrown if buffer is
     * not large enough to hold required objects */
    Pool *pool = init_pool(buffer, sizeof(buffer), 32, 10);
    for (int i = 0; i < 11; i++) {
        void *x = pool_malloc(pool);
        if (x != NULL) {
            memset(x, 1, 32);
        }
        printf("%p\n", x);
    }

    pool = init_pool(buffer, sizeof(buffer), 32, 10);
    for (int i = 0; i < 10; i++) {
        void *x = pool_malloc(pool);
        if (x != NULL) {
            memset(x, 1, 32);
        }
        printf("%p\n", x);
        pool_free(pool, x);
    }

    printf("\n");
}
