CXX = g++
CXXSDL = $(shell sdl2-config --cflags)
LDSDL = $(shell sdl2-config --libs)
CXXFLAGS = -Wall -c -std=c++11 $(CXXSDL)
LDFLAGS = $(LDSDL) -lSDL2_image
BIN_DIR = bin/

all: load-texture

load-texture: load-texture.o Game.o TextureManager.o
	$(CXX) $^ -o $(BIN_DIR)$@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

clean:
	rm *.o && rm $(BIN_DIR)*
