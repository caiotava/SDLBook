#ifndef __GAME__
#define __GAME__

#include<SDL2/SDL.h>

class Game
{
	public:
		Game() {}
		~Game() {}

		bool init(const char *title, int xPosition, int yPosition, int height, int width, int flags);

		void render();
		void update() {}
		void handleEvents();
		void clean();

		bool isRunning() { return running; }

	private:
		bool running;
		SDL_Window *window;
		SDL_Renderer *renderer;
};

#endif
