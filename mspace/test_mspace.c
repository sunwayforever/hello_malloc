#include "mspace_malloc.h"

char buffer[10240];

int main(int argc, char *argv[]) {
    /* NOTE: case 1, wrap malloc with default_mspace  */
    init_default_mspace(buffer, sizeof(buffer));
    for (int i = 1; i < 100; i++) {
        hxd_malloc(i);
        void *x = hxd_malloc(i);
        hxd_free(x);
    }
}
