CC=g++
BIN=bin
SRC=src
TEST=tests
SRCS=$(wildcard $(SRC)/*.cpp)
TESTS=$(wildcard $(TEST)/*.cpp)


all: main

main:
	$(CC) main.cpp -o $(BIN)/main $(SRCS)

unit-test:
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS)
