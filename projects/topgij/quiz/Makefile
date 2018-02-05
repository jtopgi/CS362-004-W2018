CFLAGS = -Wall -fpic -coverage -lm

all: testme

testme: testme.c
	gcc -o testme -g testme.c $(CFLAGS)

clean:
	rm testme *.gcno *.gcov *.gcda
