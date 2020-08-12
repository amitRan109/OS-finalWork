all: client server

client: client.o
	gcc -Wall -g -o client client.o

client.o: client.c
	gcc -Wall -g -c client.c

server: server.o
	gcc -Wall -g -o server server.o

server.o: server.c
	gcc -Wall -g -c server.c

.PHONY: clean all

clean:
	rm -f *.o 