CC=g++
BIN=bin
SRC=src
TEST=tests
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)
SRCS_NOT_MAIN=$(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))

all: main

make-dir:
	if not exist $(BIN) mkdir $(BIN)

make-dir-linux:
	mkdir -p $(BIN)

main: make-dir
	$(CC) -o $(BIN)/main $(SRCS)

linux: make-dir-linux
	$(CC) -o $(BIN)/main $(SRCS)

test: make-dir
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS_NOT_MAIN)

linux-unit-test: make-dir-linux
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS_NOT_MAIN)

clean:
	rm -r $(BIN)

