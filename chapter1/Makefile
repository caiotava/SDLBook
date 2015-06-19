CXX = g++
CXXSDL = $(shell sdl2-config --cflags)
LDSDL = $(shell sdl2-config --libs)
CXXFLAGS = -Wall -c -std=c++11 $(CXXSDL)
LDFLAGS = $(LDSDL)
BIN_DIR = bin/

all: hello-world-1 hello-world-2

hello-world-1: hello-world-1.o
	$(CXX) $< -o $(BIN_DIR)$@ $(LDFLAGS)

hello-world-2: hello-world-2.o Game.o
	$(CXX) $< -o $(BIN_DIR)$@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

clean:
	rm *.o && rm $(BIN_DIR)*
