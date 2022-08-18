#include <stdio.h>

#include "malloc.h"

char buffer[10240];
char buffer2[10240];

int main(int argc, char *argv[]) {
    /* NOTE: case 1, wrap malloc with default_mspace  */
    init_default_mspace(buffer, sizeof(buffer));
    for (int i = 0; i < 10; i++) {
        void *x = malloc(32);
        printf("%p\n", x);
    }
    printf("\n");

    /* NOTE: case 2, use mspace directly */
    mspace space = create_mspace_with_base(buffer2, sizeof(buffer2), 0);
    for (int i = 0; i < 10; i++) {
        void *x = mspace_malloc(space, 32);
        mspace_free(space, x);
        printf("%p\n", x);
    }
}
