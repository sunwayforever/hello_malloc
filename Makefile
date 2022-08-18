all: test.elf

CFLAGS := -O2

test.elf:test.o malloc.o
	gcc ${CFLAGS} $^ -o $@

clean:
	-rm test.o malloc.o test.elf
