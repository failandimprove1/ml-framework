CC=g++
BIN=bin
SRC=src
TEST=tests
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)
SRCS_NOT_MAIN=$(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))

all: main

make_dir:
	if not exist $(BIN) mkdir $(BIN)

main: make_dir
	$(CC) -o $(BIN)/main $(SRCS)

unit-test: make_dir
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS_NOT_MAIN)

clean:
	rm $(BIN)/*

