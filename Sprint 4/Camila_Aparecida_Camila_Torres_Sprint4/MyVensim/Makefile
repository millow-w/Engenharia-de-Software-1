CC = g++
CFLAGS = -Wall -std=c++11
SRC = src
TEST_FUNCIONAL = test/funcional
BIN = bin

all: $(BIN)/main
	$(BIN)/main

$(BIN)/main: $(TEST_FUNCIONAL)/main.cpp $(TEST_FUNCIONAL)/funcional_tests.cpp $(SRC)/system.cpp $(SRC)/flow.cpp $(SRC)/model.cpp
	$(CC) $(CFLAGS) $(TEST_FUNCIONAL)/main.cpp $(TEST_FUNCIONAL)/funcional_tests.cpp $(SRC)/system.cpp $(SRC)/flow.cpp $(SRC)/model.cpp -o $(BIN)/main
