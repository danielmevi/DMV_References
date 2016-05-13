# Compiler Engine
CC = g++ -std=c++0x

# Directory structure
BIND = ./bin
LIBD = ./lib
HPPD = ./include
CPPD = ./core
OUTD = ./output

# Make searchpath
VPATH = $(BIND):$(LIBD):$(HPPD):$(CPPD)

# Compilation flags
CFLAGS = -c -Wall -I $(HPPD)

# Library flags
LFLAGS = -fast -L $(LIBD) -lm -lrt -lpthread -Wall

# OBJ = User imput object name without dot and file type
# example: OBJ=CPPName
OBJECT = $(i:%=%.o) 

exec.o: $(BIND) $(OUTD) $(OBJECT)
	$(CC) -o $(OUTD)/$@ $(BIND)/$(OBJECT) $(LFLAGS)

# Directory compilation
$(BIND):
	mkdir $(BIND)
$(OUTD):
	mkdir $(OUTD)

# Compile rule
%.o: %.cpp
	$(CC) -o $(BIND)/$@ $< $(CFLAGS)

clean:
	rm -rf $(BIND)
	rm -rf $(OUTD)
