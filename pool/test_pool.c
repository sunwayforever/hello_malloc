#include <stdio.h>
#include <string.h>

#include "pool_config_64.h"
#include "pool_malloc.h"

int main(int argc, char *argv[]) {
    INIT_POOLS
    for (int i = 1; i < 100; i++) {
        hxd_malloc(i);
        void *x = hxd_malloc(i);
        memset(x, 1, i);
        printf("%p\n", x);
        hxd_free(x);
    }
}
