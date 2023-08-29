#.PHONY clean all

CXX = g++

SOURCES = $(wildcard *.cpp)
# main.cpp SquareEquationSolve.cpp test.cpp interface.cpp
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
APPLICATION = Square

all: $(APPLICATION)

$(APPLICATION): $(OBJECTS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@
clean:
	rm -rf *.o Square
#.PHONY
