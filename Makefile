CC=gcc
BIN=bin
SRC=src
TEST=tests
SRCS=$(wildcard $(SRC)/*.c)
TESTS=$(wildcard $(TEST)/*.c)

check:
	@echo $(SRCS)
	@echo $(TESTS)

main:
	$(CC) main.c -o $(BIN)/main $(SRCS)

unit-test:
	$(CC) -o $(BIN)/tests $(TESTS) $(SRCS)
