#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>

int main(int argc, char **argv) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
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
		SDL_SetRenderDrawColor(renderer, 13, 12, 63, 0.8);
		SDL_RenderPresent(renderer);
		TTF_Font *font = TTF_OpenFont("JetBrainsMonoNL-Regular.ttf", (int)24);
		SDL_Color color = {255, 255, 255};
		SDL_Surface *surface = TTF_RenderText_Solid(font, "Ted", color);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
		int texW, texH;
		SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
		SDL_Rect dstrect = {0, 0, texW, texH};
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}
	
	return 0;
}
