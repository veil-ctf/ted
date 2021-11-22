#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL.h>

int main(int argc, char **argv) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("Ted", 0, 0, 600, 800, SDL_WINDOW_RESIZABLE);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	bool quit = false;
	while (!(quit)) {
		SDL_Event event = {0};
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
			} break;
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		
		SDL_RenderPresent(renderer);

	}
	
	return 0;
}
