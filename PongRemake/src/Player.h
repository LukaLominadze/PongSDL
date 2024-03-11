#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player(Vector2 spawnPosition, Vector2 size);
	~Player();

	void Movement(const Uint8* keystate, SDL_Scancode upInput, SDL_Scancode downInput, int speed);
};

