CC=gcc
BIN=bin
SRC=src
TEST=tests
SRCS=$(wildcard $(SRC)/*.c)
TESTS=$(wildcard $(TEST)/*.c)

all: main

main:
	$(CC) main.c -o $(BIN)/main $(SRCS)

unit-test:
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS)
