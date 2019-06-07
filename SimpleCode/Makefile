# Compiler Engine
CC = g++

# Directory structure
BIND = ./bin
LIBD = ./lib
HPPD = ./include
CPPD = ./core
OUTD = ./output

# Make searchpath
VPATH = $(BIND):$(LIBD):$(HPPD):$(CPPD)

# Compilation flags
CFLAGS = -c -I $(HPPD)

# Library flags
LFLAGS = -fast -L $(LIBD) -lm -lrt -lpthread -Wall

DEPENDENCIES = alpha.o
OBJECT = ALPHA.o

$(OBJECT): $(BIND) $(OUTD) $(DEPENDENCIES)
	$(CC) -o $(OUTD)/$@ $(BIND)/$(DEPENDENCIES) $(LFLAGS)

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
