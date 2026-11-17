all:
	mkdir -p src
	mv -n *.c *.h src/ 2>/dev/null || true
	$(MAKE) bin/esercizio1

bin/esercizio1: build/esercizio1.o
	mkdir -p bin
	cc -o bin/esercizio1 build/esercizio1.o

build/esercizio1.o: src/esercizio1.c
	mkdir -p build
	cc -Isrc -c src/esercizio1.c -o build/esercizio1.o

clean:
	rm -rf build bin