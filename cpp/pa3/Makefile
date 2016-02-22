CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = Matrix.cpp tester.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Matrix

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
