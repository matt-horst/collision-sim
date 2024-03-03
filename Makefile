CC = g++
CFLAGS = -Wall -Wpedantic
LDFLAGS = -lSDL2
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
SRCS = $(shell find $(SRC_DIR)/ -name "*.cpp")
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
BINS = $(patsubst %, $(BIN_DIR)/%, main)

all: dirs $(BINS)

$(BIN_DIR)/main: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(BIN_DIR)/* $(OBJ_DIR)/*
