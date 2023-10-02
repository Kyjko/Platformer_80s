#include <iostream>
#include <SDL.h>
#include <cstdlib>
#include <ctype.h>
#include <vector>
#include "Map.hpp"
#include "common.hpp"
#include "display.hpp"

#undef main

errno_t Setup(SDL_Window** w, SDL_Renderer** r) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "[!!] : Cannot initialize SDL, exiting...\n";
		return -2;
	}
	
	std::vector<const char*> errmsg;
	*w = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED);
	if (*w == nullptr) {
		errmsg.push_back("Cannot create SDL_Window");
	}
	if (errmsg.empty()) {
		*r = SDL_CreateRenderer(*w, -1, NULL);
		if (*r == nullptr) {
			errmsg.push_back("Cannot create SDL_Renderer");
		}
	}

	if (!errmsg.empty()) {
		for (auto& msg : errmsg) {
			std::cout << "[-] : " << msg << "\n";
		}
		return -1;
	}

	return 0;
}

void Loop(SDL_Window* w, SDL_Renderer* r) {
	Map* map = new Map(WIDTH, HEIGHT);
	uint32_t* fbuffer = (uint32_t*) malloc(sizeof(uint32_t)*WIDTH*HEIGHT);

	SDL_Texture* ftex = SDL_CreateTexture(r, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
		if (ftex == nullptr) {
			std::cout << "[-] Cannot create SDL_Texture!\n";
			return;
	}

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT: {
				quit = true;
				break;
			}
			default: {}
			}
		}

		SDL_UpdateTexture(ftex, NULL, fbuffer, (int)WIDTH*sizeof(uint32_t));
		
		clearscreen(fbuffer, 0x00);
		map->Render(fbuffer);

		SDL_RenderCopy(r, ftex, NULL, NULL);
		SDL_RenderPresent(r);
	}

	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);

	free(fbuffer);

	delete map;
}

int main(int argc, char** argv) {

	SDL_Window* w;
	SDL_Renderer* r;

	errno_t c = Setup(&w, &r);
	if (!c) {
		Loop(w, r);
	}

	std::cout << "Exiting..." << "\n";

	return 0;
}