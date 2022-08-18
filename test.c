// 2022-08-18 10:26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "malloc.h"

int main(int argc, char *argv[]) {
    void *x = malloc(10);
    void *y = malloc(10);
    printf("%p %p\n", x, y);
}
