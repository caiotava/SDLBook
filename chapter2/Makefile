CXX = g++
SDL = -framework SDL2
CXXFLAGS = -Wall -c -std=c++11
INCLUDE = -Iinclude/
LDFLAGS = $(SDL)
BIN_DIR = bin/

all: load-texture

load-texture: load-texture.o Game.o
	$(CXX) $(LDFLAGS) $^ -o $(BIN_DIR)$@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

clean:
	rm *.o && rm $(BIN_DIR)*
