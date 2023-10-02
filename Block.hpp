#pragma once

#include "common.hpp"
#include "display.hpp"
#include <stdint.h>

class Block {
public:
	Block(float x, float y, float width, float height);
	~Block();
	void Render(uint32_t* r);

private:
	float x, y;
	float width, height;
};

