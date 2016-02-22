CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = date.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = lab_7

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *~ *.o $(EXECUTABLE)
