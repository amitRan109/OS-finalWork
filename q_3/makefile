all:set_policy

set_policy: set_policy.o
	gcc -Wall -g -o set_policy set_policy.o

set_policy.o: set_policy.c
	gcc -Wall -g -c set_policy.c

.PHONY: clean all

clean:
	rm -f *.o 