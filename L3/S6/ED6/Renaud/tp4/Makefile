# Variable déclaration
CC = gcc
CFLAGS = -Wall -g

# Directives
.PHONY: re clean

# Rules
all: main

catalan.o : catalan.c catalan.h
	$(CC) $(CFLAGS) -c catalan.c

print_result.o : print_result.c print_result.h
	$(CC) $(CFLAGS) -c print_result.c

main.o : main.c print_result.h catalan.h
	$(CC) $(CFLAGS) -c main.c

main : main.o print_result.o catalan.o
	$(CC) -o main main.o print_result.o catalan.o

clean:
	rm -f main *.o *~ \#*

re: clean main
