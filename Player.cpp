#include "Player.hpp"

Player::Player(float x, float y) : x(x), y(y) {

}

void Player::Render(SDL_Renderer* r) {
	SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
	
}

Player::~Player() {
}
