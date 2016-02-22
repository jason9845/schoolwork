all: permute

permute: permute.o
	g++ -o permute permute.o
	rm -f *~ *.o core

permute.o: permute.cpp
	g++ -c permute.cpp -g

clean:
	rm -f *~ *.o permute core
