all: dir_traversal

dir_traversal: dir_traversal.o
	gcc -Wall -g -o dir_traversal dir_traversal.o

dir_traversal.o: dir_traversal.c
	gcc -Wall -g -c dir_traversal.c

.PHONY: clean all

clean:
	rm -f *.o 