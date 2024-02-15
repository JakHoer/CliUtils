FILES := $(wildcard src/*.c)
BIN := $(patsubst src/%.c,%.o,$(FILES))

override CFLAGS := -Wall $(CFLAGS)

.PHONY: all clean test
all: $(BIN)
	ar rcs bin/libCliUtils.a $(patsubst %,bin/%,$(BIN))
	
%.o: src/%.c
	gcc -c $(CFLAGS) -Iinclude/ $< -o bin/$@

clean:
	rm -f $(patsubst ($(wildcard bin/*.c) $(wildcard bin/*.h)), , $(wildcard bin/*))
	rm -f test/test.exe

test:
	gcc test/*.c $(CFLAGS) -Iinclude/ -Lbin -lCliUtils -o test/test.exe