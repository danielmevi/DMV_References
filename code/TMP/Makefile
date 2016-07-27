CXX = g++
#CXX = clang

SRC_DIR = src
BIN_DIR = bin

CFLAGS = -Weffc++ -Wall --std=c++1y 

SRC = binary2decimal
SRC2 = enableIf

all : $(SRC) $(SRC2)

$(SRC) : $(SRC_DIR)/$(SRC).cpp
	$(CXX) $(CFLAGS) $(SRC_DIR)/$(SRC).cpp -o $(BIN_DIR)/$(SRC).o

$(SRC2) : $(SRC_DIR)/$(SRC2).cpp
	$(CXX) $(CFLAGS) $(SRC_DIR)/$(SRC2).cpp -o $(BIN_DIR)/$(SRC2).o

MKDIR:
	mkdir bin

clean:
	rm -r $(BIN_DIR)
