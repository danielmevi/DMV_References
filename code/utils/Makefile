# Compiler Engine
CC = g++ -std=c++1y

# Directory structure
BIND = ./bin
HPPD = ./include
CPPD = ./src
OUTD = ./lib

# Make searchpath
VPATH = $(BIND):$(HPPD):$(CPPD)

# Library flags
LFLAGS = -Weffc++ -Wold-style-cast -Wall -O3 -shared

# OBJ = User imput object name without dot and file type
# example: gmake i=CPPName
OBJECT = $(i:%=%.cpp) 

exec.o: $(BIND) $(OUTD) $(OBJECT)
	$(CC) -o $(OUTD)/$@ $(CPPD)/$(OBJECT) $(LFLAGS)

# Directory compilation
$(BIND):
	mkdir $(BIND)
$(OUTD):
	mkdir $(OUTD)

clean:
	rm -rf $(BIND)
	rm -rf $(OUTD)
