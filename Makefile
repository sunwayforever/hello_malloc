all: test_mspace.elf test_bump_pointer.elf

CFLAGS := -Os -DONLY_MSPACES -DNO_MALLOC_STATS -DNO_MALLINFO -DHAVE_MMAP=0 \
	-DNO_MSPACES_FOOTPRINT -DNO_MSPACES_REALLOC -DNO_MSPACES_IALLOC -DNO_MSPACES_MEMALIGN \
	-DNO_MSPACES_BULK_FREE -DNO_MSPACES_MALLOPT

CC := gcc
# CC := mips-linux-musl-gcc
# CC := aarch64-linux-android23-clang
# CC := riscv64-linux-gnu-gcc

MSPACE_SRC := $(wildcard mspace/*.c)
MSPACE_OBJ := $(patsubst %.c,%.o,${MSPACE_SRC})

BUMP_POINTER_SRC := $(wildcard bump_pointer/*.c)
BUMP_POINTER_OBJ := $(patsubst %.c,%.o,${BUMP_POINTER_SRC})

test_mspace.elf:${MSPACE_OBJ}
	${CC} ${CFLAGS} $^ -o $@ -static

test_bump_pointer.elf:${BUMP_POINTER_OBJ}
	${CC} ${CFLAGS} $^ -o $@

test: test_mspace.elf test_bump_pointer.elf
	./test_mspace.elf
	./test_bump_pointer.elf

clean:
	rm -rf *.elf ${MSPACE_OBJ} ${BUMP_POINTER_OBJ}
