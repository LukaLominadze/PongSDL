#include "Player.h"

Player::Player(Vector2 spawnPosition, Vector2 size):
	Object(spawnPosition, size)
{
}

Player::~Player()
{
}

void Player::Movement(const Uint8* keystate, SDL_Scancode upInput, SDL_Scancode downInput, int speed)
{
	if (keystate[upInput]) {
		Move(Vector2(0, -speed));
	}
	if (keystate[downInput]) {
		Move(Vector2(0, speed));
	}
}
