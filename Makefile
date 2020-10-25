CC = gcc
LIB = src/
build:
	mkdir build
	$(CC) -c src/eError.c src/eMatrix.c src/eTest.c -I$(LIB)
	$(CC) *.o -o test
	mv *.o ./build
clean:
	rm -r build
