#include <stdlib.h>
#include <string.h>

#include "mspace_malloc.h"

char buffer[10240];

int main(int argc, char *argv[]) {
    srand(1);
    for (int i = 0; i < 1024; i++) {
        init_default_mspace(buffer, sizeof(buffer));
        for (int j = 0; j < 10; j++) {
            int size = rand() % 1024 + 1;
            void *x = hxd_malloc(size);
            void *y = hxd_malloc(size);
            memset(x, 1, size);
            memset(y, 2, size);
            hxd_free(y);
        }
    }
}
