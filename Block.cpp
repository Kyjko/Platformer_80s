#include "Block.hpp"

Block::Block(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {
	
}

void Block::Render(uint32_t* r) {

	for(int i = x; i <= x+width; i++) {
		for (int j = y; j <= y+height; j++) {
			putpixel(r, i, j, 0xFFFF00FF);
		}
	}

	// update blocks
	y += 1;
	
}

Block::~Block() {
}
