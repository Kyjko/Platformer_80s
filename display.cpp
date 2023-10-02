#include "display.hpp"

int putpixel(uint32_t* r, uint32_t x, uint32_t y, uint32_t v) {
	size_t idx = y * WIDTH + x;
	if (!IN(idx, 0, WIDTH*HEIGHT)) {
		return -1;
	}
	r[idx] = v;
	return 0;
}

int clearscreen(uint32_t* r, uint32_t v) {
	for (size_t i = 0; i < WIDTH*HEIGHT; i++) {
		r[i] = v;
	}

	return 0;
}