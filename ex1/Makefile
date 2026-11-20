.PHONY: all test clean

all: bin/test_ex1

test: bin/test_ex1
	./bin/test_ex1

bin/test_ex1: build/test_ex1.o build/selection_sort.o build/quick_sort.o build/hybrid_sort.o
	mkdir -p bin
	cc -o bin/test_ex1 build/test_ex1.o build/selection_sort.o build/quick_sort.o build/hybrid_sort.o

build/%.o: src/%.c
	mkdir -p build
	cc -Wall -Wextra -Isrc -Isrc/h -c $< -o $@

clean:
	rm -rf build bin