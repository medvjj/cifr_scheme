CFLAGS=-Wall -g

all: cifr_scheme

cifr_scheme: main.o and_2.o timer.o
	cc $(CFLAGS) main.o and_2.o timer.o -o cifr_scheme

main.o: main.c
	cc $(CFLAGS) -c main.c

and_2.o: and_2.c
	cc $(CFLAGS) -c and_2.c

timer.o: timer.c
	cc $(CFLAGS) -c timer.c

clean:
	rm -rf *.o cifr_scheme
