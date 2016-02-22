all: tjain

tjain: tjain.o
	g++ -o tjain tjain.o
	rm -f *~ *.o core

tjain.o: tjain.cpp
	g++ -c tjain.cpp -g

clean:
	rm -f *~ *.o tjain core