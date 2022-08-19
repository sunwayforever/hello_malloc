#ifndef POOL_CONFIG_64_H
#define POOL_CONFIG_64_H
#include <stddef.h>
size_t BIN_SIZE = 64;
char buffer_1[3920];
char buffer_2[5136];
void *POOLS[]={
    0,
    buffer_1,
    buffer_2,
};
#define INIT_POOLS \
init_pool(buffer_1, sizeof(buffer_1), 64, 61);\
init_pool(buffer_2, sizeof(buffer_2), 128, 40);
#endif //POOL_CONFIG_64_H