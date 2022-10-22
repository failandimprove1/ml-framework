CC=g++
BIN=bin
SRC=src
TEST=tests
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)


all: main

make_dir:
	mkdir $(BIN)

main: make_dir
	$(CC) main.cpp -o $(BIN)/main $(SRCS)

unit-test: make_dir
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS)

clean:
	rm $(BIN)/*

