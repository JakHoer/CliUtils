FILES := $(wildcard src/*.c)
BIN := $(patsubst src/%.c,%.o,$(FILES))

override CFLAGS := -Wall $(CFLAGS)

.PHONY: all clean test
all: $(BIN)
	ar rcs bin/libCliUtils.a $(patsubst %,bin/%,$(BIN))

dir:
	mkdir bin

%.o: src/%.c | dir
	gcc -c $(CFLAGS) -Iinclude/ $< -o bin/$@

debug:
	$(MAKE) CFLAGS=-g
