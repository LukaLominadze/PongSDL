#include "Ball.h"
#include "Log.h"
#include <math.h>

Ball::Ball(Vector2 spawnPosition, Vector2 size, Vector2 delta, Vector2 screenSize) :
	Object(spawnPosition, size)
{
	this->delta = delta;
	this->screenSize = screenSize;
}

Ball::~Ball()
{
}

void Ball::LaunchBall()
{
	x = (screenSize.x - w) / 2;
	y = (screenSize.y - h) / 2;
}

void Ball::MoveBall()
{
	Move(delta);
}

void Ball::Collision(const SDL_Rect* player1, const SDL_Rect* player2)
{
	// The player we are colliding with
	SDL_Rect currentPlayer;
	if (x > screenSize.y / 2) {
		currentPlayer = *player2;
	}
	else {
		currentPlayer = *player1;
	}
	// Player collision
	if (SDL_HasIntersection(this, &currentPlayer)) {
		if (((y + h) > currentPlayer.y && y < currentPlayer.y)) {
			y = currentPlayer.y - h;
			delta.y = -abs(delta.y);	
		}
		else if (y < (currentPlayer.y + currentPlayer.h) && (y + h) >(currentPlayer.y + currentPlayer.h)) {
			y = currentPlayer.y + currentPlayer.h;
			delta.y = abs(delta.y);
		}
		else {
			delta.x = -delta.x;
		}
	}
	// Screen bounds
	if (x < 0 || x > screenSize.x) {
		LaunchBall();
	}
	else if (y < 0 || (y + h) > screenSize.y) {
		delta.y = -delta.y;
	}
}
