#include "Map.hpp"

Map::Map(uint32_t w, uint32_t h) : width(w), height(h) {
	uint8_t c = ReadMapLayout();
	std::cout << "ReadMapLayout() :" << c << "\n";
}

void Map::Render(uint32_t* r) {
	for (auto& b : layout) {
		b.Render(r);
	}
}

uint8_t Map::ReadMapLayout() {
	int q = 40;
	for (int i = 0; i < width / q; i++) {
		layout.push_back(Block(i*q, 300 + i*i/2, q, 25));
	}
	return 0;
}

Map::~Map() {
	layout = std::vector<Block>();
}
