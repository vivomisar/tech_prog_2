CC=clang++
SRC=src
BUILD_DIR=build
NAME=lab1
CFLAGS=-Wall -std=c++17 -g

all:
	$(CC) -o $(BUILD_DIR)/$(NAME) $(SRC)/*.cpp $(CFLAGS)

run: all
	./$(BUILD_DIR)/$(NAME)