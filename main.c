#include "SDL.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char ** argv) {
  /* Declare window and renderer */
  SDL_Window * window;
  SDL_Renderer * renderer;

  /* Initialize SDL */
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("SDLBook_cmake",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            WINDOW_WIDTH, WINDOW_HEIGHT,
			    0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  /* Main game loop */
  while (!SDL_QuitRequested()) {
    SDL_RenderClear(renderer);
    /* Place your simulation code and rendering code here */
    SDL_RenderPresent(renderer);
  }

  /* Deinitialize everything */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
