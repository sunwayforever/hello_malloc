// 2022-08-18 10:26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "malloc.h"

char buffer[10240];
int main(int argc, char *argv[]) {
    mspace space = create_mspace_with_base(buffer, 10240, 0);
    for (int i = 0; i < 10; i++) {
        void *x = mspace_malloc(space, 10);
        printf("%p\n", x);
    }
}
