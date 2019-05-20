CC=gcc
CFLAGS=-Wall -g -O -std=c11

all: crawler test_StrHT

test_StrHT: test_StrHT.o StrHT.o
	$(CC) $(CFLAGS) -o test_StrHT test_StrHT.o StrHT.o

crawler: crawler.o WebGraph.o
	$(CC) $(CFLAGS) -o crawler crawler.o WebGraph.o StrHT.o

crawler.o: crawler.c
	$(CC) -c $(CFLAGS) crawler.c

WebGraph.o: WebGraph.c StrHT.o
	$(CC) -c $(CFLAGS) WebGraph.c
	ld -r WebGraph.o StrHT.o

StrHT.o: StrHT.c
	$(CC) -c $(CFLAGS) StrHT.c

clean:
	rm *.o

scrub:
	rm crawler test_StrHT
	rm *.o