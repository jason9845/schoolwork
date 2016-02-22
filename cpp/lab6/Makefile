all: reverse

reverse: reverse.o
	g++ -o reverse reverse.o
	rm -f *~ *.o core

reverse.o: reverse.cpp
	g++ -c reverse.cpp -g

clean:
	rm -f *~ *.o reverse core
