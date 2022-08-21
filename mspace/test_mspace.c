#include <stdlib.h>
#include <string.h>

#include "mspace_malloc.h"

extern void malloc_benchmark();

char buffer[10240000];

int main(int argc, char *argv[]) {
    init_default_mspace(buffer, sizeof(buffer));
    malloc_benchmark();
}
