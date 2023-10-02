#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>

class Player {
public:
	Player(float x, float y);
	~Player();
	void Render(SDL_Renderer* r);

private:
	float x, y;
};

