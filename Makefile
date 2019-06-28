CC=gcc
CFLAGS=-Wall -g -O -std=c11
ADTS=StrHT.o WebGraph.o IntList.o

all: crawler test_StrHT test_WebGraph

crawler: crawler.o $(ADTS)
	$(CC) $(CFLAGS) -o crawler crawler.o $(ADTS) -lcurl

crawler.o: crawler.c
	$(CC) -c $(CFLAGS) crawler.c

# testing executables

test_WebGraph: test_WebGraph.o $(ADTS)
	$(CC) $(CFLAGS) -o test_WebGraph test_WebGraph.o $(ADTS)

test_StrHT: test_StrHT.o $(ADTS)
	$(CC) $(CFLAGS) -o test_StrHT test_StrHT.o $(ADTS)

# testing program .o files

test_StrHT.o: test_StrHT.c
	$(CC) -c $(CFLAGS) test_StrHT.c

test_WebGraph.o: test_WebGraph.c
	$(CC) $(CFLAGS) -c test_WebGraph.c

# Helper .o files

urlParse.o: urlParse.c
	$(CC) $(CFLAGS) -c urlParse.c

# ADT object files

WebGraph.o: WebGraph.c
	$(CC) -c $(CFLAGS) WebGraph.c

StrHT.o: StrHT.c
	$(CC) -c $(CFLAGS) StrHT.c

IntList.o: IntList.c
	$(CC) -c $(CFLAGS) IntList.c

clean:
	rm *.o

scrub:
	rm crawler test_StrHT test_WebGraph
	rm *.o