CC=g++
CFLAGS=-fPIC -g
LDFLAGS=-shared
SOURCES=src/edit_distance.cpp
OBJECTS=$(SOURCES:.c=.o)
EXAMPLE=examples/test.cpp
EXECUTABLE=test
TARGET_LIB=edit_distance.so

all: $(TARGET_LIB) $(EXECUTABLE)

$(EXECUTABLE): $(TARGET_LIB)
	$(CC) $(EXAMPLE) $(CFLAGS) $(TARGET_LIB) -o $@

$(TARGET_LIB): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	rm -rf src/*.o examples/*.o test *.so
