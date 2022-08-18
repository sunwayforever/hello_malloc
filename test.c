// 2022-08-18 10:26
#include <stdio.h>

#include "malloc.h"

char buffer[10240];
int main(int argc, char *argv[]) {
    init_default_mspace(buffer, sizeof(buffer));
    for (int i = 0; i < 10; i++) {
        void *x = malloc(10);
        printf("%p\n", x);
        free(x);
    }
}
