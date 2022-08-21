#include <stdlib.h>
#include <string.h>

#include "pool_config_64.h"
#include "pool_malloc.h"

extern void malloc_benchmark();

int main(int argc, char *argv[]) {
    INIT_POOLS
    malloc_benchmark();
}
