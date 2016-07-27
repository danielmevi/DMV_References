# Compiler Engine
# With gcc6.1.0 there is no need for this, since c++11 is default setting
#CC = g++ -std=c++0x
CXX = /usr/intel/pkgs/gcc/6.1.0/bin/g++

# Directory structure
BIND = ./bin
CPPD = ./src

# Compilation flags
CFLAGS = -Wall -Woverloaded-virtual -Woverloaded-virtual -Wreorder -fsized-deallocation 
CFLAGS_EXTRA = -Weffc++

# OBJ = User imput object name without dot and file type
# example: i=CPPName
OBJECT = $(i:%=%.cpp) 

exec.o: $(BIND) $(CPPD)/$(OBJECT)
	$(CXX) $(CFLAGS) -o $(BIND)/$@ $(CPPD)/$(OBJECT) 

# Directory compilation
$(BIND):
	mkdir $(BIND)

clean:
	rm -rf $(BIND)
