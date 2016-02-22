CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = List.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = lab09

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
