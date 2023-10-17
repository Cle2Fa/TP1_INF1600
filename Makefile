CC=gcc
CFLAGS=-g -m32 -g -Wall
RM=rm -f
TARGET_EXEC=exec
TARGET_TESTS=tests
OBJECTS_EXEC=main.o functions.o helpers.o
OBJECTS_TESTS=tests.o functions.o helpers.o

.PHONY: all clean test build_exec

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: exec test

build_exec: $(TARGET_EXEC)

test: $(TARGET_TESTS)
	./$(TARGET_TESTS)

$(TARGET_EXEC): $(OBJECTS_EXEC)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_TESTS): $(OBJECTS_TESTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o exec test $(TARGET_EXEC) $(TARGET_TESTS)
