#include "mspace_config.h"
#include "mspace_malloc.h"

extern void malloc_benchmark();
extern void malloc_check();

int main(int argc, char *argv[]) {
    init_spaces();
    malloc_benchmark();
    init_spaces();
    malloc_check();
}
