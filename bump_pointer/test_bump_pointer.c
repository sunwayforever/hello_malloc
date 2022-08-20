#include <stdio.h>

#include "bump_pointer_malloc.h"

char buffer[10240];

int main(int argc, char *argv[]) {
    init_default_mspace(buffer, sizeof(buffer));
    for (int i = 0; i < 10; i++) {
        void *x = hxd_malloc(1);
        printf("%p\n", x);
    }
    printf("\n");

    void *x = hxd_malloc(12);
    printf("%p\n", x);
    free(x);
}
