CC=gcc
AR=ar
FLAGs = -Wall -g

all: isort txtfind

txtfind: stringMain.o myString.o
	$(CC) $(FLAGS) -o txtfind stringMain.o myString.o

isort: insertionMain.o insertion.o
	$(CC) $(FLAGS) -o isort insertionMain.o insertion.o

myString.o: myString.c myString.h
	$(CC) -fPIC $(FLAGS) -c myString.c

stringMain.o: stringMain.c
	$(CC) $(FLAGS) -c stringMain.c

insertion.o: insertion.c insertion.h
	$(CC) -fPIC $(FLAGS) -c insertion.c

insertionMain.o: insertionMain.c
	$(CC) $(FLAGS) -c insertionMain.c

.PHONY: clean all 

clean:
	-rm -f *.o *.a isort txtfind