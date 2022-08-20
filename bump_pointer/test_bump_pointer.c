#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bump_pointer_malloc.h"

char buffer[10240];

int main(int argc, char *argv[]) {
    srand(time(NULL));
    for (int i = 0; i < 10240; i++) {
        init_default_mspace(buffer, sizeof(buffer));
        for (int j = 0; j < 10; j++) {
            int size = rand() % 1024 + 1;
            void *x = hxd_malloc(size);
            memset(x, 1, size);
        }
    }
}
