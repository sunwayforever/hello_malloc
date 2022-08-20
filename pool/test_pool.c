#include <stdlib.h>
#include <string.h>

#include "pool_config_64.h"
#include "pool_malloc.h"

int main(int argc, char *argv[]) {
    INIT_POOLS

    srand(1);
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 10; j++) {
            int size = rand() % 1024 + 1;
            void *x = hxd_malloc(size);
            void *y = hxd_malloc(size);
            memset(x, 1, size);
            memset(y, 2, size);
            free(y);
        }
    }
}
