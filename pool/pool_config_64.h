#ifndef POOL_CONFIG_64_H
#define POOL_CONFIG_64_H
#include <stddef.h>
size_t BIN_SIZE = 64;
char buffer_1[40400];
char buffer_2[86672];
char buffer_3[128080];
char buffer_4[159504];
char buffer_5[200336];
char buffer_6[233872];
char buffer_7[279568];
char buffer_8[320528];
char buffer_9[388816];
char buffer_10[389136];
char buffer_11[488592];
char buffer_12[457744];
char buffer_13[528336];
char buffer_14[568080];
char buffer_15[616336];
char buffer_16[671760];
char buffer_17[37008];
void *POOLS[]={
    0,
    buffer_1,
    buffer_2,
    buffer_3,
    buffer_4,
    buffer_5,
    buffer_6,
    buffer_7,
    buffer_8,
    buffer_9,
    buffer_10,
    buffer_11,
    buffer_12,
    buffer_13,
    buffer_14,
    buffer_15,
    buffer_16,
    buffer_17,
};
#define INIT_POOLS \
init_pool(buffer_1, sizeof(buffer_1), 64, 631);\
init_pool(buffer_2, sizeof(buffer_2), 128, 677);\
init_pool(buffer_3, sizeof(buffer_3), 192, 667);\
init_pool(buffer_4, sizeof(buffer_4), 256, 623);\
init_pool(buffer_5, sizeof(buffer_5), 320, 626);\
init_pool(buffer_6, sizeof(buffer_6), 384, 609);\
init_pool(buffer_7, sizeof(buffer_7), 448, 624);\
init_pool(buffer_8, sizeof(buffer_8), 512, 626);\
init_pool(buffer_9, sizeof(buffer_9), 576, 675);\
init_pool(buffer_10, sizeof(buffer_10), 640, 608);\
init_pool(buffer_11, sizeof(buffer_11), 704, 694);\
init_pool(buffer_12, sizeof(buffer_12), 768, 596);\
init_pool(buffer_13, sizeof(buffer_13), 832, 635);\
init_pool(buffer_14, sizeof(buffer_14), 896, 634);\
init_pool(buffer_15, sizeof(buffer_15), 960, 642);\
init_pool(buffer_16, sizeof(buffer_16), 1024, 656);\
init_pool(buffer_17, sizeof(buffer_17), 1088, 34);
#endif //POOL_CONFIG_64_H