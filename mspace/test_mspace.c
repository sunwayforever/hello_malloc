#include <stdlib.h>
#include <string.h>

#include "mspace_config.h"
#include "mspace_malloc.h"

extern void malloc_benchmark();

int main(int argc, char *argv[]) {
    INIT_SPACES

    malloc_benchmark();
}
