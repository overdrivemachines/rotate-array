
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

rotate-array: rotate-array.o
	$(CC) $(CFLAGS) -o rotate-array rotate-array.o

rotate-array.o: rotate-array.cpp
	$(CC) $(CFLAGS) -c rotate-array.cpp

clean:
	rm -rf rotate-array rotate-array.o
