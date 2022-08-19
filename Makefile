all: test_mspace.elf test_bump_pointer.elf test_pool.elf

CFLAGS := -Os -DONLY_MSPACES -DNO_MALLOC_STATS -DNO_MALLINFO -DHAVE_MMAP=0 \
	-DNO_MSPACES_FOOTPRINT -DNO_MSPACES_REALLOC -DNO_MSPACES_IALLOC -DNO_MSPACES_MEMALIGN \
	-DNO_MSPACES_BULK_FREE -DNO_MSPACES_MALLOPT -MMD

CFLAGS += -DUSE_HXD_PREFIX
CFLAGS += -DDEBUG_HIST

CC := gcc
# CC := mips-linux-musl-gcc
# CC := aarch64-linux-android23-clang
# CC := riscv64-linux-gnu-gcc

MSPACE_SRC := $(wildcard mspace/*.c)
MSPACE_OBJ := $(patsubst %.c,%.o,${MSPACE_SRC})

BUMP_POINTER_SRC := $(wildcard bump_pointer/*.c)
BUMP_POINTER_OBJ := $(patsubst %.c,%.o,${BUMP_POINTER_SRC})

POOL_SRC := $(wildcard pool/*.c)
POOL_OBJ := $(patsubst %.c,%.o,${POOL_SRC})

OBJ:=${MSPACE_OBJ} ${BUMP_POINTER_OBJ} ${POOL_OBJ}
DEP := $(OBJ:.o=.d)
-include ${DEP}

test_mspace.elf:${MSPACE_OBJ}
	${CC} ${CFLAGS} $^ -o $@

test_bump_pointer.elf:${BUMP_POINTER_OBJ}
	${CC} ${CFLAGS} $^ -o $@

test_pool.elf:${POOL_OBJ}
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -rf *.elf ${OBJ} ${DEP}
