CC=gcc
CFLAGS=-Wall -g -O -std=c11

all: crawler

crawler: crawler.o WebGraph.o
	$(CC) $(CFLAGS) -o crawler crawler.o WebGraph.o

crawler.o: crawler.c
	$(CC) -c $(CFLAGS) crawler.c

WebGraph.o: WebGraph.c
	$(CC) -c $(CFLAGS) WebGraph.c

clean:
	rm *.o