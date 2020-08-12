all: check_pid

check_pid: check_pid.o
	gcc -Wall -g -o check_pid check_pid.o

check_pid.o: check_pid.c
	gcc -Wall -g -c check_pid.c

.PHONY: clean all

clean:
	rm -f *.o 
