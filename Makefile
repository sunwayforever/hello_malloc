all: test.elf

CFLAGS := -Os -DONLY_MSPACES -DNO_MALLOC_STATS -DNO_MALLINFO -DHAVE_MMAP=0 \
	-DNO_MSPACES_FOOTPRINT -DNO_MSPACES_REALLOC -DNO_MSPACES_IALLOC -DNO_MSPACES_MEMALIGN \
	-DNO_MSPACES_BULK_FREE -DNO_MSPACES_MALLOPT

CC := gcc
# CC := mips-linux-musl-gcc
# CC := aarch64-linux-android23-clang
# CC := riscv64-linux-gnu-gcc

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,${SRC})

test.elf:${OBJ}
	${CC} ${CFLAGS} $^ -o $@ -static

test: test.elf
	./test.elf

clean:
	rm -rf test.elf ${OBJ}
