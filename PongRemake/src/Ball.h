#pragma once
#include "Object.h"
class Ball : public Object
{
public:
	Ball(Vector2 spawnPosition, Vector2 size, Vector2 delta, Vector2 screenSize);
	~Ball();

	void LaunchBall();
	void MoveBall();
	void Collision(const SDL_Rect* player1, const SDL_Rect* player2);
private:
	Vector2 delta;
	Vector2 screenSize;
};

