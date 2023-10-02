#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "common.hpp"
#include "Block.hpp"

class Map {
public:
	Map(uint32_t w, uint32_t h);
	~Map();
	void Render(uint32_t* r);
	uint8_t ReadMapLayout();

private:
	uint32_t width, height;
	uint8_t id;
	std::vector<Block> layout;
};

