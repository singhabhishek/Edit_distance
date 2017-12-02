CC=g++
CFLAGS=-fPIC -g -std=c++11
LDFLAGS=-shared
SOURCES=src/edit_distance.cpp
OBJECTS=$(SOURCES:.c=.o)
EXAMPLE1=examples/test.cpp
EXECUTABLE1=test
EXAMPLE2=examples/compare_dna_sequence.cpp
EXECUTABLE2=compare_dna_sequence
TARGET_LIB=edit_distance.so

all: $(TARGET_LIB) $(EXECUTABLE1) $(EXECUTABLE2)

$(EXECUTABLE2): $(TARGET_LIB)
	$(CC) $(EXAMPLE2) $(CFLAGS) $(TARGET_LIB) -o $@

$(EXECUTABLE1): $(TARGET_LIB)
	$(CC) $(EXAMPLE1) $(CFLAGS) $(TARGET_LIB) -o $@

$(TARGET_LIB): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	rm -rf src/*.o examples/*.o test compare_dna_sequence *.so *.csv
