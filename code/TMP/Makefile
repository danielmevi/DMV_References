#CXX = g++
CXX = clang

SRC_DIR = src/tmp
BIN_DIR = bin

CFLAGS = -rdynamic -ldl -Wall --std=c++1y 

SRC = binary2decimal

all : $(SRC)

$(SRC) : $(SRC_DIR)/$(SRC).cpp
	$(CXX) $(CFLAGS) $(SRC_DIR)/$(SRC).cpp -o $(BIN_DIR)/$(SRC).o

MKDIR:
	mkdir bin

clean:
	rm -r $(BIN_DIR)
