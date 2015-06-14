CXX = g++
SDL = -lSDL2
CXXFLAGS = -Wall -c -std=c++11
INCLUDE = -Iinclude/
LDFLAGS = $(SDL) -lSDL2_image
BIN_DIR = bin/

all: load-texture

load-texture: load-texture.o Game.o TextureManager.o
	$(CXX) $(LDFLAGS) $^ -o $(BIN_DIR)$@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

clean:
	rm *.o && rm $(BIN_DIR)*
