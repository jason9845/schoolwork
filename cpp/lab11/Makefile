CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=CheckBuilding.cpp building.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=building

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
