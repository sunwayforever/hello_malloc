#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bump_pointer_malloc.h"

extern void malloc_benchmark();

char buffer[102400000];

int main(int argc, char *argv[]) {
    init_default_mspace(buffer, sizeof(buffer));
    malloc_benchmark();
}
