// 2022-08-22 13:55
#ifndef MSPACE_CONFIG_H
#define MSPACE_CONFIG_H
#include <stddef.h>

static char buffer_1[1024000];
static char buffer_2[10240000];

void* SPACES[] = {
    0,
    0,
};

extern void* init_mspace(void* base, size_t capacity);

#define INIT_SPACES                                      \
    SPACES[0] = init_mspace(buffer_1, sizeof(buffer_1)); \
    SPACES[1] = init_mspace(buffer_2, sizeof(buffer_2));

int N_SPACES = sizeof(SPACES) / sizeof(SPACES[0]);

#endif  // MSPACE_CONFIG_H
