#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bump_pointer_config.h"
#include "bump_pointer_malloc.h"

extern void malloc_benchmark();
extern void malloc_check();
int main(int argc, char* argv[]) {
    init_spaces();
    malloc_benchmark();
    malloc_check();
}
