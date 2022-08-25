// 2022-08-25 21:43
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define N 1024
int malloc_check() {
    int *ptr[N];
    memset(ptr, 0, N * sizeof(int *));
    for (int i = 1; i < N; i++) {
        ptr[i] = (int *)malloc(i * sizeof(int));
        assert(ptr[i] != NULL);
        for (int j = 0; j < i; j++) {
            ptr[i][j] = i;
        }
    }
    for (int i = 1; i < N; i++) {
        if (ptr[i] == NULL) {
            break;
        }
        for (int j = 0; j < i; j++) {
            assert(ptr[i][j] == i);
        }
    }
    for (int i = N - 1; i >= 1; i--) {
        if (ptr[i] == NULL) {
            continue;
        }
        for (int j = 0; j < i; j++) {
            ptr[i][j] = i;
        }
    }
    for (int i = 1; i < N; i++) {
        if (ptr[i] == NULL) {
            break;
        }
        for (int j = 0; j < i; j++) {
            assert(ptr[i][j] == i);
        }
    }
}
