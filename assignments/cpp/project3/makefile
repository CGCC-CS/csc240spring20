CC=g++ 
CPPFLAGS=--std=c++11 -Wall -pedantic

all: project3.cpp term.o polynomial.o
	$(CC) $(CPPFLAGS) project3.cpp term.o polynomial.o -o project3

term.o: term.cpp
	$(CC) $(CPPFLAGS) -c term.cpp

polynomial.o: polynomial.cpp
	$(CC) $(CPPFLAGS) -c polynomial.cpp

clean:
	rm -f *.o *.exe *~
